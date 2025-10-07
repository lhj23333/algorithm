#include <iostream>
#include <vector>

using namespace std;

class Solution {
    int process(int k, vector<int> &prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2*k + 1, 0));
        for(int i = 0; i < k; i ++) {
            dp[0][2*i + 1] = -prices[0];
        }

        for(int i = 1; i < prices.size(); i ++) {
            dp[i][0] = dp[i - 1][0];
            for(int j = 0; j < k; j ++) {
                dp[i][2*j + 1] = max(dp[i - 1][2*j] - prices[i], dp[i - 1][2*j + 1]);
                dp[i][2*(j + 1)] = max(dp[i - 1][2*j + 1] + prices[i], dp[i - 1][2*(j + 1)]);
            }
        }
        return dp[prices.size() - 1][2*k];
    }

public:
    int maxProfit(int k, vector<int> &prices) {
        if(k == 0 || prices.size() < 2) return 0;
        return process(k, prices);
    }
};

void test(const vector<int>& prices, int k, int expected) {
    Solution sol;
    int result = sol.maxProfit(k, const_cast<vector<int>&>(prices));
    cout << "Prices: ";
    for (int p : prices) cout << p << " ";
    cout << "k: " << k << " => Expected: " << expected << ", Got: " << result << endl;
}

int main() {
    test({2,4,1}, 2, 2); // Simple case, max profit is 2
    test({3,2,6,5,0,3}, 2, 7); // Two transactions: buy at 2, sell at 6; buy at 0, sell at 3
    test({1,2,4,2,5,7,2,4,9,0}, 2, 13); // Two best transactions
    test({1,2}, 1, 1); // Only one transaction possible
    test({5,4,3,2,1}, 2, 0); // Prices decreasing, no profit
    test({1,2,3,4,5}, 2, 4); // Prices increasing, best is buy at 1, sell at 5
    test({}, 2, 0); // Empty prices
    test({1}, 2, 0); // Only one price
    test({1,2,3,4,5}, 0, 0); // Zero transactions allowed
    test({1,3,2,8,4,9}, 2, 13); // Two transactions: buy at 1, sell at 8; buy at 4, sell at 9
    return 0;
}

