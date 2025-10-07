#include <iostream>
#include <vector>

using namespace std;

class Solution {
    int process(vector<int> &prices, int fee) {
        int len = prices.size();
        vector<vector<int>> dp(len, vector<int>(2, 0));
        dp[0][0] = -prices[0];

        for(int i = 1; i < len; i ++) {
            dp[i][0] = max(dp[i - 1][1] - prices[i], dp[i - 1][0]);
            dp[i][1] = max(dp[i - 1][0] + prices[i] - fee, dp[i - 1][1]);
        }
        return dp[len - 1][1];
    }

public:
    int maxProfit(vector<int>& prices, int fee) {
        if(prices.size() < 2) return 0;
        return process(prices, fee);
    }
};

int main() {
    Solution solution;
    
    // Test case 1: Basic example
    vector<int> prices1 = {1, 3, 2, 8, 4, 9};
    int fee1 = 2;
    cout << "Test 1: " << solution.maxProfit(prices1, fee1) << " (expected: 8)" << endl;
    
    // Test case 2: Single price
    vector<int> prices2 = {5};
    int fee2 = 1;
    cout << "Test 2: " << solution.maxProfit(prices2, fee2) << " (expected: 0)" << endl;
    
    // Test case 3: Two prices
    vector<int> prices3 = {1, 4};
    int fee3 = 2;
    cout << "Test 3: " << solution.maxProfit(prices3, fee3) << " (expected: 1)" << endl;
    
    // Test case 4: High transaction fee
    vector<int> prices4 = {1, 3, 7, 5, 10, 3};
    int fee4 = 3;
    cout << "Test 4: " << solution.maxProfit(prices4, fee4) << " (expected: 6)" << endl;
    
    // Test case 5: Decreasing prices
    vector<int> prices5 = {9, 8, 7, 6, 5};
    int fee5 = 1;
    cout << "Test 5: " << solution.maxProfit(prices5, fee5) << " (expected: 0)" << endl;
    
    // Test case 6: Zero fee
    vector<int> prices6 = {1, 4, 2, 8};
    int fee6 = 0;
    cout << "Test 6: " << solution.maxProfit(prices6, fee6) << " (expected: 9)" << endl;
    
    return 0;
}
