#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int process(vector<int> &cost) {
        vector<int> dp(cost.size() + 1);
        dp[0] = 0;
        dp[1] = 0;

        for(size_t i = 2; i <= cost.size(); i ++) {
            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        }
        return dp[cost.size()];
    }

public:
    int minCostClimbingStairs(vector<int> &cost) {
        if(cost.size() < 2) return 0;
        return process(cost);
    }
};

int main() {
    Solution solution;
    
    // Test case 1: Example from problem
    vector<int> cost1 = {10, 15, 20};
    cout << "Test 1: " << solution.minCostClimbingStairs(cost1) << " (Expected: 15)" << endl;
    
    // Test case 2: Another example
    vector<int> cost2 = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    cout << "Test 2: " << solution.minCostClimbingStairs(cost2) << " (Expected: 6)" << endl;
    
    // Test case 3: Minimum size
    vector<int> cost3 = {1, 2};
    cout << "Test 3: " << solution.minCostClimbingStairs(cost3) << " (Expected: 1)" << endl;
    
    // Test case 4: All same costs
    vector<int> cost4 = {5, 5, 5, 5, 5};
    cout << "Test 4: " << solution.minCostClimbingStairs(cost4) << " (Expected: 10)" << endl;
    
    // Test case 5: Increasing costs
    vector<int> cost5 = {1, 2, 3, 4, 5, 6};
    cout << "Test 5: " << solution.minCostClimbingStairs(cost5) << " (Expected: 9)" << endl;
    
    // Test case 6: Large first cost
    vector<int> cost6 = {100, 1, 1, 1};
    cout << "Test 6: " << solution.minCostClimbingStairs(cost6) << " (Expected: 2)" << endl;
    
    return 0;
}
