#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<string> path;
    vector<vector<string>> result;

    bool isPalindrome(string str) {
        if(str.empty()) return true;
        
        char *left = &str[0];
        char *right = &str[str.size() - 1];

        while(left < right) {
            if(*left != *right) return false;
            left ++;
            right --;
        }
        return true;
    }

    void backtracking(const string &s, size_t startIndex) {
        if(startIndex == s.size()) {
            result.push_back(path);
            return;
        }

        for(size_t i = startIndex; i < s.size(); i ++) {
            string str = s.substr(startIndex, i - startIndex + 1);
            if(isPalindrome(str)) {
                path.push_back(str);
                backtracking(s, i + 1);
                path.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {
        path.clear();
        result.clear();
        if(s.empty()) return {};
        backtracking(s, 0);
        return result;
    }     
};

// Helper: correct partition implementation for expected results
static bool isPal(const string &s, int l, int r) {
    while (l < r) {
        if (s[l++] != s[r--]) return false;
    }
    return true;
}
static void backtrackCorrect(const string &s, int start, vector<string> &path, vector<vector<string>> &res) {
    if (start == (int)s.size()) {
        res.push_back(path);
        return;
    }
    for (int i = start; i < (int)s.size(); ++i) {
        if (isPal(s, start, i)) {
            path.push_back(s.substr(start, i - start + 1));
            backtrackCorrect(s, i + 1, path, res);
            path.pop_back();
        }
    }
}
static vector<vector<string>> correctPartition(const string &s) {
    vector<vector<string>> res;
    vector<string> path;
    backtrackCorrect(s, 0, path, res);
    return res;
}

static void printVV(const vector<vector<string>> &v) {
    cout << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        cout << "[";
        for (size_t j = 0; j < v[i].size(); ++j) {
            cout << "\"" << v[i][j] << "\"";
            if (j + 1 < v[i].size()) cout << ", ";
        }
        cout << "]";
        if (i + 1 < v.size()) cout << ", ";
    }
    cout << "]";
}

int main()
{
    vector<string> tests = {"aab", "aba", "a", "aa", "abba"};

    Solution sol;
    for (const string &t : tests) {
        cout << "Input: \"" << t << "\"\n";

        auto actual = sol.partition(t);
        cout << "Actual result:\n";
        printVV(actual);
        cout << "\n";

        auto expected = correctPartition(t);
        cout << "Correct result:\n";
        printVV(expected);
        cout << "\n----------\n";
    }

    return 0;
}