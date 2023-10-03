#include <iostream>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>


using std::map;
using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::getline;

bool stringIsUniqueChars();
bool stringIsPermutation();
void replaceWhiteSpaces();

int main() {

    string input;
    while(true) {
        cout << "1. Unique charaters\n" << "2. Permutation\n" << "3. Replace White space\n" << "Select mode: ";
        cin >> input;

        switch (stoi(input)) {
            case 1:
                cout << "Unique: " << ((stringIsUniqueChars()) ? "Yes\n" : "No\n");
                break;
            case 2:
                cout << "Permute: " << ((stringIsPermutation()) ? "Yes\n" : "No\n");
                break;
            case 3:
                replaceWhiteSpaces();
                break;
            default:
                cout << "Invalid selection\n";
                exit(EXIT_FAILURE);
        }
    }
    

}

void replaceWhiteSpaces() {
    string s1;
    string s2 = "";
    
    getline(cin, s1);
    cout << "S1: " << s1 << endl;

    for (char ch : s1) {
        if(ch != ' ') {
            s2 += ch;
        }
        else {
            s2 += "%20";
        }
    }

    cout << "Replace: " << s2 << endl;

}

bool stringIsPermutation() {

    string s1;
    string s2;
    cin >> s1;
    cin >> s2;

    map<char, size_t> map1;
    map<char, size_t> map2;

    
    for (int i = 0; i < s1.size(); i++) {
        ++map1[s1[i]];
    }

    for (int i = 0; i < s2.size(); i++) {
        ++map2[s2[i]];
    }

    if(map1 == map2) {
        return true;
    }
    return false;
    
}

bool stringIsUniqueChars() {

    string s1;
    cin >> s1;

    if (s1.size() > 128) return false;

    map<char, size_t> map;
    
    for (int i = 0; i < s1.size(); i++) {
        ++map[s1[i]];
    }

    for (const auto &w : map) {
        if(w.second > 1) return false;
    }
    return true;
}