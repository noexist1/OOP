#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

bool str_compair(std::pair<std::string, int> a, std::pair<std::string, int> b)
{
	return(a.second > b.second);
}

int main(int argc, char** argv)
{
	if (argc == 1)
	{
		cout << "Underfined Args";
		return 1;
	}
	if (argc == 2)
	{
		cout << "Required output arg";
		return 1;
	}
	string input_file = argv[1];
	string output_file = argv[2];
	ifstream input;
	list<string> list_of_words;
	string word;
	string file_str;
	int total_words = 0;
	input.open(input_file);
	while (getline(input, file_str))
	{
		for (int i = 0; i < file_str.length(); i++)
		{
			if (file_str[i] >= 'a' && file_str[i] <= 'z' || file_str[i] >= 'A' && file_str[i] <= 'Z' || file_str[i] >= '0' && file_str[i] <= '9')
			{
				char temp = file_str[i];
				word.push_back(temp);
			}
			else if (word.length() != 0)
			{
				list_of_words.push_back(word);
				word.clear();
				total_words += 1;
			}
			else
			{
				continue;
			}
		}
		if (word.length() > 0)
		{
			list_of_words.push_back(word);
			word.clear();
			total_words += 1;
		}
	}
	input.close();
	map<string, int> words_total; 
	while (list_of_words.size() != 0)
	{
		string word = list_of_words.front();
		list_of_words.pop_front();
		map<string, int>::iterator it;
		it = words_total.find(word);
		if (it != words_total.end())
		{
			words_total[word] += 1;
		}
		else
		{
			words_total.insert(pair<string, int>(word, 1));
		}
	}
	list_of_words.clear();
	vector<pair<string, int>> vector_words_total;
	for (map<string, int>::iterator it = words_total.begin(); it != words_total.end(); it++)
	{
		vector_words_total.push_back(make_pair(it->first, it->second));
	}
	words_total.clear();
	std::sort(vector_words_total.begin(), vector_words_total.end(), str_compair);
	ofstream output; 
	output.open(output_file);
	for (vector<pair<string, int>>::iterator it = vector_words_total.begin(); it != vector_words_total.end(); it++)
	{
		double flat_frequency = ((double)it->second / (double)total_words * 100.0);
		output << it->first << ',' << it->second << ',' << flat_frequency << '%' << '\n';
	}
}