#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:    
    int process(vector<int> &prices, int k) {
        vector<vector<int>> dp(prices.size(), vector<int>(2*k + 1, 0));
        for(int i = 0; i < k; i ++) {
            dp[0][2*i + 1] = -prices[0];
        }

        for(int i = 1; i < prices.size(); i ++) {
            dp[i][0] = dp[i - 1][0];
            for(int j = 0; j < k; j ++) {
                dp[i][2*j + 1] = max(dp[i - 1][2*j + 1], dp[i - 1][2*j] - prices[i]);
                dp[i][2*(j + 1)] = max(dp[i - 1][2*(j + 1)], dp[i - 1][2*j + 1] + prices[i]);
            }
        }
        return dp[prices.size() - 1][2*k];
    }

public:
    int maxProfit(vector<int> &prices) {
        if(prices.size() < 2) return 0;
        return process(prices, 2);
    }
};

void test(const vector<int>& prices, int expected) {
    Solution sol;
    int result = sol.maxProfit(const_cast<vector<int>&>(prices));
    cout << "Prices: ";
    for (int p : prices) cout << p << " ";
    cout << "\nExpected: " << expected << ", Got: " << result << endl;
    cout << (result == expected ? "PASS" : "FAIL") << endl << endl;
}

int main() {
    test({1, 2, 3, 4, 5}, 4);          // Increasing prices, max profit is 4
    test({7, 6, 4, 3, 1}, 0);          // Decreasing prices, no profit
    test({3, 3, 5, 0, 0, 3, 1, 4}, 6); // Multiple transactions
    test({1, 2, 4, 2, 5, 7, 2, 4, 9, 0}, 13); // Complex case
    test({2, 4, 1}, 2);                // One transaction possible
    test({1}, 0);                      // Only one price, no transaction
    test({}, 0);                       // Empty prices
    test({1, 2}, 1);                   // Simple increasing
    test({2, 1}, 0);                   // Simple decreasing
    return 0;
}
