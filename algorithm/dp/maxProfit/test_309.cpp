#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int process(vector<int> &prices) {
        int len = prices.size();
        vector<vector<int>> dp(len, vector<int>(3, 0));
        dp[0][0] = -prices[0];

        for(int i = 1; i < len; i ++) {
            dp[i][0] = max(dp[i - 1][0],dp[i - 1][2] - prices[i]);
            dp[i][1] = dp[i - 1][0] + prices[i];
            dp[i][2] = max(dp[i - 1][2], dp[i - 1][1]);
        }
        return max(dp[len - 1][1], dp[len - 1][2]);
    }

public:
    int maxProfit(vector<int> &prices) {
        if(prices.size() < 2) return 0;
        return process(prices);
    }
};

int main() {
    Solution sol;

    // Test 1: Basic increasing prices
    vector<int> prices1 = {1, 2, 3, 0, 2};
    cout << "Test 1: " << sol.maxProfit(prices1) << endl; // Expected: 3

    // Test 2: All prices the same
    vector<int> prices2 = {5, 5, 5, 5, 5};
    cout << "Test 2: " << sol.maxProfit(prices2) << endl; // Expected: 0

    // Test 3: Decreasing prices
    vector<int> prices3 = {5, 4, 3, 2, 1};
    cout << "Test 3: " << sol.maxProfit(prices3) << endl; // Expected: 0

    // Test 4: Prices with multiple peaks
    vector<int> prices4 = {1, 2, 4, 2, 5, 7, 2, 4, 9, 0};
    cout << "Test 4: " << sol.maxProfit(prices4) << endl; // Expected: 13

    // Test 5: Only one price
    vector<int> prices5 = {10};
    cout << "Test 5: " << sol.maxProfit(prices5) << endl; // Expected: 0

    // Test 6: Empty prices
    vector<int> prices6 = {};
    cout << "Test 6: " << sol.maxProfit(prices6) << endl; // Expected: 0

    // Test 7: Prices with cooldown effect
    vector<int> prices7 = {1, 2, 3, 0, 2, 1, 4};
    cout << "Test 7: " << sol.maxProfit(prices7) << endl; // Expected: 5

    return 0;
}
