using namespace std;

class number
{
public:
    int num[4];

    void zeros() {
        for (int i = 0; i < 4; ++i)
            num[i] = 0;
    }

    void random()
    {
        for (int i = 0; i < 4; ++i)
            num[i] = (1 + rand() % 10);

    }

    void print()
    {
        for (int i = 0; i < 4; ++i) {
            cout << num[i] << " ";
        }
        cout << "\n";
    }

    number convert(int n)
    {
        number result;
        result.zeros();
        try {
            if (n < 1000 || n > 9999)
                throw -1;
        }
        catch (int a){
            std::cerr << "\nCaught exception '" << a << "': invalid number for converting" << '\n';
            result.zeros();
            return result;
        }
        int i = 3;
        while (n){
            result.num[i] = n % 10;
            n /= 10;
            i--;
        }
        return result;
    }

    int fwd_convert()
    {
        return num[0]*1000 + num[1]*100 + num[2]*10 + num[3];
    }

    string search(number a, int n, int standing)
    {
        string result;
        for (int i = 0; i < 4; ++i) {
            if ((n == a.num[i]) && (standing == i)) {
                result = "bull";
                return result;
            }
            else if (n == a.num[i])
                result = "cow";
        }
        return result;
    }

private:

};

class state{
public:
    map<string,int> value;
    void init() {

        pair<string, int> temp;
        temp.second = 0;
        temp.first = "bull";
        value.insert(temp);
        temp.first = "cow";
        value.insert(temp);
    }
    state checkout(number a, number b)
    {
        state result;
        result.init();
        std::map<string, int>::iterator it;
        for (int i = 0; i < 4; ++i) {
            result.value.find(a.search(b, a.num[i], i))->second++; //
        }
        return result;
    }
    void print() {
        std::map<string, int>::iterator it;
        for (it=value.begin(); it != value.end(); it++) {
            cout.width(5);
            cout << it->second << " ";
        }
    }

    bool victory(){
        if (value.find("bull")->second == 4)
            return true;
        else
            return false;
    }

};

class game_table{
public:
    vector<pair<int, state>> list;
    vector<number> turns;
    void show(){
        vector<pair<int, state>>::iterator it;
        cout.width(5);
        cout << " attempt   bull   cow     guessed\n";
        int i = 1;
        vector<number>::iterator it2;
        it2 = turns.begin();
        for (it = list.begin(); it < list.end(); ++it) {
            cout.width(8);
            cout << i << ' ';
            it->second.print();
            cout.width(6);
            i++;
            it2->print();
            it2++;
        }
        cout << '\n';
    }
    void make_turn(state new_turn, number move){
        list.push_back(pair<int, state> {list.size(), new_turn});
        turns.push_back(move);
    }
    void clear(){
        list.clear();
        turns.clear();
    }

};



