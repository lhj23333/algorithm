#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    string path;
    vector<string> result;

    bool isLegal(string str) {
        if(str.empty()) return false;
        if(str.size() != 1 && str[0] == '0') return false;
        int val = stoi(str);
        if(val > 255) return false;
        return true;
    }

    void backtracking(string s, size_t startIndex, int k) {
        if(k == 0 && startIndex == s.size()) {
            result.push_back(path);
            return ;
        }

        size_t mem = s.size() - startIndex;
        if(mem < k || mem > 3 * k) return ;
        for(size_t i = startIndex; i < s.size() && i < startIndex + 3; i++) {
            string str = s.substr(startIndex, i - startIndex + 1);
            if(isLegal(str)) {
                path += str;
                if(k > 1) path += '.';
                backtracking(s, i + 1, k - 1);
                if(k > 1) path.pop_back();
                path.resize(path.size() - str.size());
            }
        }
    }

public:
    vector<string> restoreIpAddresses(string s) {
        path.clear();
        result.clear();
        if(s.empty()) return {};
        backtracking(s, 0, 4);
        return result;
    }
};

int main()
{
    Solution sol;
    auto printVec = [](const vector<string>& v){
        cout << "[";
        for(size_t i = 0; i < v.size(); ++i) {
            if(i) cout << ", ";
            cout << v[i];
        }
        cout << "]";
    };

    vector<pair<string, vector<string>>> tests = {
        {"25525511135", {"255.255.11.135", "255.255.111.35"}},
        {"0000", {"0.0.0.0"}},
        {"010010", {"0.10.0.10", "0.100.1.0"}},
        {"1111", {"1.1.1.1"}},
        {"101023", {"1.0.10.23", "1.0.102.3", "10.1.0.23", "10.10.2.3", "101.0.2.3"}},
        {"", {}},
        {"1111111111111", {}}
    };

    for(const auto &tc : tests) {
        const string &input = tc.first;
        const vector<string> &expected = tc.second;
        vector<string> output = sol.restoreIpAddresses(input);

        cout << "Input: \"" << input << "\"\n";
        cout << "Output: ";
        printVec(output);
        cout << "  Expected: ";
        printVec(expected);
        cout << "\n\n";
    }

    return 0;
}