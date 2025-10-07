#include <iostream>
#include <vector>
#include <cstdint>

using namespace std;

class Solution {
private:
    int process(int amount, vector<int> &coins) {
        vector<uint64_t> dp(amount + 1, 0);
        dp[0] = 1;

        for(size_t i = 0; i < coins.size(); i++) {
            for(size_t j = coins[i]; j <= amount; j ++) {
                dp[j] += dp[j - coins[i]];
            }
        }
        return dp[amount];
    }

public:
    int change(int amount, vector<int> &coins) {
        return process(amount, coins);
    }
};

int main() {
    Solution solution;
    vector<int> coins;
    
    // Test 8: Empty coins array
    coins = {};
    cout << "Test 8: coins=[], amount=5, result=" << solution.change(5, coins) << " (expected: 1)" << endl;
    
    // Test 9: Amount is 0 with empty coins
    coins = {};
    cout << "Test 9: coins=[], amount=0, result=" << solution.change(0, coins) << " (expected: 1)" << endl;
    
    // Test 10: Large amount that cannot be made
    coins = {3, 5};
    cout << "Test 10: coins=[3,5], amount=4, result=" << solution.change(4, coins) << " (expected: 0)" << endl;
    
    // Test 11: Amount equals largest coin
    coins = {1, 3, 5, 10};
    cout << "Test 11: coins=[1,3,5,10], amount=10, result=" << solution.change(10, coins) << " (expected: 10)" << endl;
    
    // Test 12: Small amount with multiple ways
    coins = {1, 2, 3};
    cout << "Test 12: coins=[1,2,3], amount=4, result=" << solution.change(4, coins) << " (expected: 4)" << endl;
    
    // Test 13: Duplicate coins
    coins = {2, 2, 5};
    cout << "Test 13: coins=[2,2,5], amount=6, result=" << solution.change(6, coins) << " (expected: 5)" << endl;
    
    // Test 14: Single coin larger than amount
    coins = {10};
    cout << "Test 14: coins=[10], amount=5, result=" << solution.change(5, coins) << " (expected: 0)" << endl;
    
    // Test 15: Amount 1 with coin 1
    coins = {1};
    cout << "Test 15: coins=[1], amount=1, result=" << solution.change(1, coins) << " (expected: 1)" << endl;
    
    // Test 16: Complex case with many combinations
    coins = {1, 2, 5, 10};
    cout << "Test 16: coins=[1,2,5,10], amount=15, result=" << solution.change(15, coins) << " (expected: 22)" << endl;
    
    // Test 17: Prime number coins
    coins = {2, 3, 7};
    cout << "Test 17: coins=[2,3,7], amount=12, result=" << solution.change(12, coins) << " (expected: 4)" << endl;
    
    return 0;
}
