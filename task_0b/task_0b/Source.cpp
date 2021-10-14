#include <iostream>
#include <fstream>
#include <list>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
bool str_comp(std::pair<std::string, int> a, std::pair<std::string, int> b) {
	return(a.second > b.second);
}
int main(int argc, char** argv) {
	using namespace std;
	if (argc == 1) {
		cout << "Underfined Args\n";
		return 1;
	}
	if (argc == 2) {
		cout << "Required output arg\n";
		return 1;
	}
	string input_file = argv[1];
	string output_file = argv[2];
	ifstream in_file;
	list<string> list_of_words;
	string word;
	string str_from_file;
	int num_of_words = 0;
	in_file.open(input_file);
	while (getline(in_file, str_from_file)) {
		for (int i = 0; i < str_from_file.length(); i++) { 
			if (str_from_file[i] >= 'a' && str_from_file[i] <= 'z' ||
				str_from_file[i] >= 'A' && str_from_file[i] <= 'Z' ||
				str_from_file[i] >= '0' && str_from_file[i] <= '9')
			{
				char c = str_from_file[i];
				word.push_back(c);

			}
			else if (word.length() == 0) { 
				continue;
			}
			else { 
				list_of_words.push_back(word);
				word.clear();
				num_of_words += 1;
			}
		}
		if (word.length() > 0) { 
			list_of_words.push_back(word);
			word.clear();
			num_of_words += 1;
		}
	}
	in_file.close(); 
	map<string, int> words_frequencies;
	while (list_of_words.size() != 0) {
		string word = list_of_words.front();
		list_of_words.pop_front();
		map<string, int>::iterator it;
		it = words_frequencies.find(word);
		if (it != words_frequencies.end()) {
			words_frequencies[word] += 1;
		}
		else {
			words_frequencies.insert(pair<string, int>(word, 1));
		}
	}
	list_of_words.clear();
	vector<pair<string, int>> vector_words_frequencies;
	for (map<string, int>::iterator it = words_frequencies.begin(); it != words_frequencies.end(); it++) {
		vector_words_frequencies.push_back(make_pair(it->first, it->second));
	}
	words_frequencies.clear();
	std::sort(vector_words_frequencies.begin(), vector_words_frequencies.end(), str_comp);
	ofstream out_file;
	out_file.open(output_file);
	for (vector<pair<string, int>>::iterator it = vector_words_frequencies.begin(); it != vector_words_frequencies.end(); it++) {
		double flat_frequency = ((double)it->second / (double)num_of_words * 100.0);
		cout.precision(3);
		out_file << it->first << ',' << it->second << ',' << flat_frequency << '%' << '\n';
	}
}