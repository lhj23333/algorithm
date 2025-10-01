#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std; 

class Solution {
public:
    bool isFind(string s, string t, string target, size_t strlen) {
        unordered_map<char, int> mapS;
        unordered_map<char, int> mapT;
        unordered_map<char, int> mapTarget;
        for(size_t i = 0; i < strlen; i ++) {
            mapS[s[i]] ++;
            mapT[t[i]] ++;
            mapTarget[target[i]] ++;
        }

        for(size_t i = 0; i < strlen; i ++) {
            if(mapTarget[target[i]] > mapS[target[i]] + mapT[target[i]]) return false;
        }

        return true;
    }
};

int main() {
    string s;
    string t;
    string target;
    size_t strLen;

    cin >> strLen;
    cin >> s;
    cin >> t;
    cin >> target;

    Solution sol;
    cout << sol.isFind(s, t, target, strLen);

    return 0;
}