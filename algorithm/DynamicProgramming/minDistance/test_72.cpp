#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int process(string word1, string word2) {
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));
        for(int i = 1; i <= word1.size(); i ++) dp[i][0] = i;
        for(int i = 1; i <= word2.size(); i ++) dp[0][i] = i;

        for(int i = 1; i <= word2.size(); i ++) {
            for(int j = 1; j <= word1.size(); j ++) {
                if(word2[i - 1] == word1[j - 1]) dp[j][i] = dp[j - 1][i - 1];
                else dp[j][i] = min(dp[j - 1][i - 1], min(dp[j - 1][i], dp[j][i - 1])) + 1;
            }
        }
        return dp[word1.size()][word2.size()];
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
    cout << "Test 1: " << solution.minDistance("horse", "ros") << " (Expected: 3)" << endl;
    
    // Test case 2: Basic example
    cout << "Test 2: " << solution.minDistance("intention", "execution") << " (Expected: 5)" << endl;
    
    // Test case 3: Empty strings
    cout << "Test 3: " << solution.minDistance("", "") << " (Expected: 0)" << endl;
    cout << "Test 4: " << solution.minDistance("abc", "") << " (Expected: 3)" << endl;
    cout << "Test 5: " << solution.minDistance("", "xyz") << " (Expected: 3)" << endl;
    
    // Test case 6: Identical strings
    cout << "Test 6: " << solution.minDistance("same", "same") << " (Expected: 0)" << endl;
    
    // Test case 7: Single character strings
    cout << "Test 7: " << solution.minDistance("a", "b") << " (Expected: 1)" << endl;
    cout << "Test 8: " << solution.minDistance("a", "a") << " (Expected: 0)" << endl;
    
    // Test case 9: One string is substring of another
    cout << "Test 9: " << solution.minDistance("cat", "cats") << " (Expected: 1)" << endl;
    cout << "Test 10: " << solution.minDistance("test", "te") << " (Expected: 2)" << endl;
    
    // Test case 11: Completely different strings
    cout << "Test 11: " << solution.minDistance("abc", "xyz") << " (Expected: 3)" << endl;
    
    // Test case 12: Longer strings
    cout << "Test 12: " << solution.minDistance("algorithm", "logarithm") << " (Expected: 3)" << endl;
    
    return 0;
}
