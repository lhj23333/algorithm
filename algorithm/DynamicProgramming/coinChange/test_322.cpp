#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int process(vector<int> &coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;

        for(size_t i = 0; i < coins.size(); i ++) {
            for(size_t j = coins[i]; j <= amount; j ++) {
                if(dp[j - coins[i]] != INT_MAX) dp[j] = min(dp[j], dp[j - coins[i]] + 1);
            }
        }
        if(dp[amount] == INT_MAX) return -1;
        return dp[amount];
    }

public:
    int coinChange(vector<int> &coins, int amount) {
        return process(coins, amount);
    }
};

int main() {
    Solution sol;

    vector<int> coins1 = {1, 2, 5};
    int amount1 = 11;
    cout << "Test 1: " << sol.coinChange(coins1, amount1) << endl; // Expected: 3 (5+5+1)

    vector<int> coins2 = {2};
    int amount2 = 3;
    cout << "Test 2: " << sol.coinChange(coins2, amount2) << endl; // Expected: 0 (not possible)

    vector<int> coins3 = {1};
    int amount3 = 0;
    cout << "Test 3: " << sol.coinChange(coins3, amount3) << endl; // Expected: 0

    vector<int> coins4 = {1, 3, 4};
    int amount4 = 6;
    cout << "Test 4: " << sol.coinChange(coins4, amount4) << endl; // Expected: 2 (3+3 or 4+1+1)

    vector<int> coins5 = {2, 5, 10, 1};
    int amount5 = 27;
    cout << "Test 5: " << sol.coinChange(coins5, amount5) << endl; // Expected: 4 (10+10+5+2)

    vector<int> coins6 = {7, 14};
    int amount6 = 300;
    cout << "Test 6: " << sol.coinChange(coins6, amount6) << endl; // Expected: 0 (not possible)

    return 0;
}
