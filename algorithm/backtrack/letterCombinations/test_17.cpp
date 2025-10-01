#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    string letterMap[10] = {
        "",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz",
    };

    vector<char> path;
    vector<string> result;

    void backtracking(const string digits, size_t startIndex) {
        if(path.size() == digits.size()) {
            result.push_back(string(path.begin(), path.end()));
            return ;
        }

        size_t index = digits[startIndex] - '0';
        for(size_t i = 0; i < letterMap[index].size(); i ++) {
            path.push_back(letterMap[index][i]);
            backtracking(digits, startIndex + 1);
            path.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        path.clear();
        result.clear();
        if(digits.empty()) return {};
        backtracking(digits, 0);
        return result;
    }
};

static void printVec(const vector<string> &v) {
    cout << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        if (i) cout << ", ";
        cout << '"' << v[i] << '"';
    }
    cout << "]";
}

int main() {
    Solution sol;

    struct Test {
        string input;
        vector<string> expected;
    };

    vector<Test> tests = {
        {"", {}},
        {"2", {"a","b","c"}},
        {"3", {"d","e","f"}},
        {"7", {"p","q","r","s"}},
        {"9", {"w","x","y","z"}},
        {"23", {"ad","ae","af","bd","be","bf","cd","ce","cf"}},
        {"79", {"pw","px","py","pz","qw","qx","qy","qz","rw","rx","ry","rz","sw","sx","sy","sz"}},
    };

    for (const auto &t : tests) {
        auto out = sol.letterCombinations(t.input);
        cout << "Input: \"" << t.input << "\"\n";
        cout << "Output: ";
        printVec(out);
        cout << "\nExpected: ";
        printVec(t.expected);
        cout << "\n\n";
    }

    return 0;
}