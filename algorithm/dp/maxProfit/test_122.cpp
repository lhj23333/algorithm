#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int process(vector<int> &prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
        dp[0][0] = -prices[0];
        dp[0][1] = 0;

        for(int i = 1; i < prices.size(); i ++) {
            dp[i][0] = max(dp[i - 1][1] - prices[i], dp[i - 1][0]);
            dp[i][1] = max(dp[i - 1][0] + prices[i], dp[i - 1][1]);
        }
        return dp[prices.size() - 1][1];
    }

public:
    int maxProfit(vector<int> &prices) {
        if(prices.size() < 2) return 0;
        return process(prices);
    }
};

int main() {
    Solution sol;

    // Test 1: Increasing prices
    vector<int> prices1 = {1, 2, 3, 4, 5};
    cout << "Test 1: " << sol.maxProfit(prices1) << " (Expected: 4)" << endl;

    // Test 2: Decreasing prices
    vector<int> prices2 = {5, 4, 3, 2, 1};
    cout << "Test 2: " << sol.maxProfit(prices2) << " (Expected: 0)" << endl;

    // Test 3: Fluctuating prices
    vector<int> prices3 = {1, 7, 5, 3, 6, 4};
    cout << "Test 3: " << sol.maxProfit(prices3) << " (Expected: 9)" << endl;

    // Test 4: Single price
    vector<int> prices4 = {3};
    cout << "Test 4: " << sol.maxProfit(prices4) << " (Expected: 0)" << endl;

    // Test 5: Two prices, profit possible
    vector<int> prices5 = {1, 5};
    cout << "Test 5: " << sol.maxProfit(prices5) << " (Expected: 4)" << endl;

    // Test 6: Two prices, no profit
    vector<int> prices6 = {5, 1};
    cout << "Test 6: " << sol.maxProfit(prices6) << " (Expected: 0)" << endl;

    // Test 7: All prices the same
    vector<int> prices7 = {2, 2, 2, 2};
    cout << "Test 7: " << sol.maxProfit(prices7) << " (Expected: 0)" << endl;

    // Test 8: Zigzag prices
    vector<int> prices8 = {1, 2, 1, 2, 1, 2};
    cout << "Test 8: " << sol.maxProfit(prices8) << " (Expected: 3)" << endl;

    return 0;
}
