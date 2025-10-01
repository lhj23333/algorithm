#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    bool process(string s, string t) {
        vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));

        for(int i = 1; i <= s.size(); i ++) {
            for(int j = 1; j <= t.size(); j ++) {
                if(s[i - 1] == t[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return (dp[s.size()][t.size()] == s.size());
    }

public:
    bool isSubsequence(string s, string t) {
        if(s.size() == 0) return true;
        if(t.size() == 0) return false;
        return process(s, t);
    }
};

int main() {
    Solution solution;
    
    // Test case 1: Basic subsequence
    cout << "Test 1: " << (solution.isSubsequence("ace", "aec") ? "true" : "false") << endl;
    
    // Test case 2: Not a subsequence
    cout << "Test 2: " << (solution.isSubsequence("axc", "ahbgdc") ? "true" : "false") << endl;
    
    // Test case 3: Empty string s
    cout << "Test 3: " << (solution.isSubsequence("", "abc") ? "true" : "false") << endl;
    
    // Test case 4: Empty string t
    cout << "Test 4: " << (solution.isSubsequence("abc", "") ? "true" : "false") << endl;
    
    // Test case 5: Both empty
    cout << "Test 5: " << (solution.isSubsequence("", "") ? "true" : "false") << endl;
    
    // Test case 6: Same strings
    cout << "Test 6: " << (solution.isSubsequence("abc", "abc") ? "true" : "false") << endl;
    
    // Test case 7: Single character match
    cout << "Test 7: " << (solution.isSubsequence("a", "ba") ? "true" : "false") << endl;
    
    // Test case 8: Single character no match
    cout << "Test 8: " << (solution.isSubsequence("b", "acd") ? "true" : "false") << endl;
    
    // Test case 9: Longer subsequence
    cout << "Test 9: " << (solution.isSubsequence("abc", "aabbcc") ? "true" : "false") << endl;
    
    return 0;
}
