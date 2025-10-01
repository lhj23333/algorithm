#include <iostream>
#include <vector>
 
using namespace std;

class Solution {
private:
    int process(string word1, string word2) {
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));

        for(int i = 1; i <= word1.size(); i ++) {
            for(int j = 1; j <= word2.size(); j ++) {
                if(word1[i - 1] == word2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        return word1.size() + word2.size() - 2*dp[word1.size()][word2.size()];
    }

public:
    int minDistance(string word1, string word2) {
        if(word1.empty()) return word2.size();
        if(word2.empty()) return word1.size();
        return process(word1, word2);
    }
};

int main() {
    Solution solution;
    
    // Test case 1: Basic example
    cout << "Test 1: " << solution.minDistance("sea", "eat") << " (Expected: 2)" << endl;
    
    // Test case 2: One empty string
    cout << "Test 2: " << solution.minDistance("", "abc") << " (Expected: 3)" << endl;
    cout << "Test 3: " << solution.minDistance("abc", "") << " (Expected: 3)" << endl;
    
    // Test case 4: Both empty strings
    cout << "Test 4: " << solution.minDistance("", "") << " (Expected: 0)" << endl;
    
    // Test case 5: Identical strings
    cout << "Test 5: " << solution.minDistance("hello", "hello") << " (Expected: 0)" << endl;
    
    // Test case 6: No common characters
    cout << "Test 6: " << solution.minDistance("abc", "def") << " (Expected: 6)" << endl;
    
    // Test case 7: One character strings
    cout << "Test 7: " << solution.minDistance("a", "b") << " (Expected: 2)" << endl;
    cout << "Test 8: " << solution.minDistance("a", "a") << " (Expected: 0)" << endl;
    
    // Test case 9: Longer strings with partial overlap
    cout << "Test 9: " << solution.minDistance("leetcode", "etco") << " (Expected: 4)" << endl;
    
    // Test case 10: Reverse strings
    cout << "Test 10: " << solution.minDistance("abc", "cba") << " (Expected: 4)" << endl;
    
    return 0;
}
