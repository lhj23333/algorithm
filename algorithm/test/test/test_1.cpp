#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    unordered_map<char, int> map({{'R', '0'}, {'L', '0'}, {'U', 0}, {'D', 0}});

    string str;
    cin >> str;
    for(size_t i = 0; i < str.size(); i++) {
        map[str[i]] ++;
    }
    cout << map['R'] - map['L'] << " " << map['U'] - map['D'] << endl;

    return 0;
}
