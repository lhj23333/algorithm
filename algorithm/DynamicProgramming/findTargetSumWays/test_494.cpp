#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int cnt;
    
    // 1. 回溯实现
    void backtraving(vector<int> &nums, int target, size_t startIndex, int sum) {
        if(sum == target) cnt ++;

        for(size_t i = startIndex; i < nums.size() && sum <= target; i ++) {
            sum += nums[i];
            backtraving(nums, target, i + 1, sum);
            sum -= nums[i];
        }
    }

    // 2. 背包实现
    // 算法思路：在价值为物体体积背包问题的基础上套一层路径和
    int process(vector<int> &nums, int target) {
        vector<int> dp(target + 1, 0);
        dp[0] = 1;

        for(size_t i = 0; i < nums.size(); i ++) {
            for(int j = target; j >= nums[i]; j --) {
                dp[j] += dp[j - nums[i]];
            }
        }
        return dp[target];
    }

public:
    int findTargetSumWays(vector<int> &nums, int target) {
        cnt = 0;
        if(nums.size() == 1 && nums[0] == 0) return 2; 

        int allSum = 0;
        for(size_t i = 0; i < nums.size(); i ++) allSum += nums[i];
        if((allSum + target) % 2 == 1 || abs(target) > allSum) return 0;
        // return process(nums, (allSum + target)/2);
        
        backtraving(nums, (allSum + target)/2, 0, 0);
        return cnt;
    }
};

int main() {
    Solution solution;
    
    // Test case 1: Basic example
    vector<int> nums1 = {1, 1, 1, 1, 1};
    int target1 = 3;
    cout << "Test 1: " << solution.findTargetSumWays(nums1, target1) << " (expected: 5)" << endl;
    
    // Test case 2: Single element matching target
    vector<int> nums2 = {1};
    int target2 = 1;
    cout << "Test 2: " << solution.findTargetSumWays(nums2, target2) << " (expected: 1)" << endl;
    
    // Test case 3: Single element not matching target
    vector<int> nums3 = {1};
    int target3 = 2;
    cout << "Test 3: " << solution.findTargetSumWays(nums3, target3) << " (expected: 0)" << endl;
    
    // Test case 4: Target is 1
    vector<int> nums4 = {1, 0};
    int target4 = 1;
    cout << "Test 4: " << solution.findTargetSumWays(nums4, target4) << " (expected: 2)" << endl;
    
    // Test case 5: Negative target
    vector<int> nums5 = {1, 1, 2};
    int target5 = 0;
    cout << "Test 5: " << solution.findTargetSumWays(nums5, target5) << " (expected: 2)" << endl;
    
    // Test case 6: Impossible target (odd sum + even target)
    vector<int> nums6 = {1, 2};
    int target6 = 0;
    cout << "Test 6: " << solution.findTargetSumWays(nums6, target6) << " (expected: 0)" << endl;

    // Test case 7:
    vector<int> nums7 = {1000};
    int target7 = -1000;
    cout << "Test 7: " << solution.findTargetSumWays(nums7, target7) << " (expected: 1)" << endl;
    
    return 0;
}
