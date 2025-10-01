#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int sumWeight;

    int process(vector<int> &stones, int target) {
        vector<int> dp(30*1000/2 + 1, 0);
        
        for(int i = 0; i < stones.size(); i ++) {
            for(int j = target;  j >= stones[i]; j --) {
                dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
                
            }
        }
        return sumWeight - dp[target] - dp[target];
    }

public:
    int lastStoneWeightII(vector<int> &stones) {
        sumWeight = 0;
        if(stones.size() == 1) return stones[0];
        for(size_t i = 0; i < stones.size(); i ++) {
            sumWeight += stones[i];
        }
        return process(stones, sumWeight / 2);
    }
};

int main() {
    Solution solution;
    
    // Test case 1: Single stone
    vector<int> stones1 = {2};
    cout << "Test 1: " << solution.lastStoneWeightII(stones1) << " (expected: 2)" << endl;
    
    // Test case 2: Two stones of different weights
    vector<int> stones2 = {2, 7};
    cout << "Test 2: " << solution.lastStoneWeightII(stones2) << " (expected: 5)" << endl;
    
    // Test case 3: Multiple stones
    vector<int> stones3 = {2, 7, 4, 1, 8, 1};
    cout << "Test 3: " << solution.lastStoneWeightII(stones3) << " (expected: 1)" << endl;
    
    // Test case 4: All stones have same weight
    vector<int> stones4 = {3, 3, 3, 3};
    cout << "Test 4: " << solution.lastStoneWeightII(stones4) << " (expected: 0)" << endl;
    
    // Test case 5: Two stones of same weight
    vector<int> stones5 = {5, 5};
    cout << "Test 5: " << solution.lastStoneWeightII(stones5) << " (expected: 0)" << endl;
    
    // Test case 6: Large numbers
    vector<int> stones6 = {31, 26, 33, 21, 40};
    cout << "Test 6: " << solution.lastStoneWeightII(stones6) << " (expected: 5)" << endl;
    
    return 0;
}
