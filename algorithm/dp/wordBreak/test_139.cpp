#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
private:
    bool process(string s, vector<string> &wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;

        for(size_t i = 1; i <= s.size(); i ++) {
            for(size_t j = 0; j < i; j ++) {
                string word = s.substr(j, i - j);
                if(wordSet.find(word) != wordSet.end() && dp[j]) dp[i] = true;
            }
        }
        return dp[s.size()];
    }

public:
    bool wordBreak(string s, vector<string> &wordDict) {
        return process(s, wordDict);
    }
};

int main() {
    Solution solution;
    
    // Test case 1: Basic word break
    string s1 = "leetcode";
    vector<string> wordDict1 = {"leet", "code"};
    cout << "Test 1: " << (solution.wordBreak(s1, wordDict1) ? "true" : "false") << endl;
    
    // Test case 2: No valid break
    string s2 = "catsandog";
    vector<string> wordDict2 = {"cats", "dog", "sand", "and", "cat"};
    cout << "Test 2: " << (solution.wordBreak(s2, wordDict2) ? "true" : "false") << endl;
    
    // Test case 3: Multiple valid breaks
    string s3 = "applepenapple";
    vector<string> wordDict3 = {"apple", "pen"};
    cout << "Test 3: " << (solution.wordBreak(s3, wordDict3) ? "true" : "false") << endl;
    
    // Test case 4: Single character
    string s4 = "a";
    vector<string> wordDict4 = {"a"};
    cout << "Test 4: " << (solution.wordBreak(s4, wordDict4) ? "true" : "false") << endl;
    
    // Test case 5: Empty string
    string s5 = "";
    vector<string> wordDict5 = {"a", "b"};
    cout << "Test 5: " << (solution.wordBreak(s5, wordDict5) ? "true" : "false") << endl;
    
    // Test case 6: Overlapping words
    string s6 = "catsanddog";
    vector<string> wordDict6 = {"cat", "cats", "and", "sand", "dog"};
    cout << "Test 6: " << (solution.wordBreak(s6, wordDict6) ? "true" : "false") << endl;
    
    return 0;
}
