#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int process(string text1, string text2) {
        vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));

        for(int i = 1; i <= text1.size(); i ++) {
            for(int j = 1; j <= text2.size(); j ++) {
                if(text1[i - 1] == text2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[text1.size()][text2.size()];
    } 

public:
    int longestCommonSubsequence(string text1, string text2) {
        if(text1.size() == 0 || text2.size() == 0) return 0;
        return process(text1, text2);
    }
};

int main() {
    Solution solution;
    
    // Test case 1: Basic example
    cout << "Test 1: " << solution.longestCommonSubsequence("abcde", "ace") << endl; // Expected: 3
    
    // Test case 2: No common subsequence
    cout << "Test 2: " << solution.longestCommonSubsequence("abc", "def") << endl; // Expected: 0
    
    // Test case 3: Empty strings
    cout << "Test 3: " << solution.longestCommonSubsequence("", "abc") << endl; // Expected: 0
    cout << "Test 4: " << solution.longestCommonSubsequence("abc", "") << endl; // Expected: 0
    
    // Test case 5: Identical strings
    cout << "Test 5: " << solution.longestCommonSubsequence("abc", "abc") << endl; // Expected: 3
    
    // Test case 6: Single character strings
    cout << "Test 6: " << solution.longestCommonSubsequence("a", "a") << endl; // Expected: 1
    cout << "Test 7: " << solution.longestCommonSubsequence("a", "b") << endl; // Expected: 0
    
    // Test case 8: Longer strings with complex pattern
    cout << "Test 8: " << solution.longestCommonSubsequence("abcdgh", "aedfhr") << endl; // Expected: 3
    
    // Test case 9: One string is substring of another
    cout << "Test 9: " << solution.longestCommonSubsequence("abc", "aabbcc") << endl; // Expected: 3
    
    // Test case 10: Reversed strings
    cout << "Test 10: " << solution.longestCommonSubsequence("abc", "cba") << endl; // Expected: 1
    
    return 0;
}
