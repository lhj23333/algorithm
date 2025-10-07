#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int allSum;

    // 1. 暴力回溯超时  
    bool backtraving(vector<int>& nums, size_t startIndex, int sum) {
        if(sum == allSum - sum) return true;

        for(size_t i = startIndex; i < nums.size(); i ++) {
            sum += nums[i];
            if(backtraving(nums, i + 1, sum)) return true;
            sum -= nums[i];
        }
        return false;
    }

    // 2. 动态规划
    //  算法思路：转化为背包问题 -> 每个物品的体积以及价值都为 nums[i]
    //           dp[i] 表示当选取[0, i]物体，容量为i的最大价值背包
    //           而当物体的价值等于其体积时，则 dp[i] 表示当前容量为i的背包其内可放下的最大体积
    //           -> dp[i] >= i , 当dp[i] == i 时，则说明存在刚好塞满背包的情况
    bool process(vector<int> &nums, int target) {
        vector<int> dp(10001, 0);

        for(int i = 0; i < nums.size(); i ++) {
            for(int j = target; j >= nums[i]; j --) {
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
            }
        }
        return dp[target] == target;
    }

public:
    bool canPartition(vector<int>& nums) {
        allSum = 0;
        if(nums.size() == 1) return false;
        for(int i = 0; i < nums.size(); i ++) {
            allSum += nums[i];
        }
        if(allSum % 2 == 1) return false;
        // return backtraving(nums, 0, 0);
        return process(nums, allSum / 2);
    }
};

int main() {
    Solution solution;
    
    // Test case 1: Basic partition possible
    vector<int> nums1 = {1, 5, 11, 5};
    cout << "Test 1: " << (solution.canPartition(nums1) ? "true" : "false") << endl;
    
    // Test case 2: Partition not possible
    vector<int> nums2 = {1, 2, 3, 5};
    cout << "Test 2: " << (solution.canPartition(nums2) ? "true" : "false") << endl;
    
    // Test case 3: Single element
    vector<int> nums3 = {1};
    cout << "Test 3: " << (solution.canPartition(nums3) ? "true" : "false") << endl;
    
    // Test case 4: Two equal elements
    vector<int> nums4 = {1, 1};
    cout << "Test 4: " << (solution.canPartition(nums4) ? "true" : "false") << endl;
    
    // Test case 5: Odd sum
    vector<int> nums5 = {1, 2, 5};
    cout << "Test 5: " << (solution.canPartition(nums5) ? "true" : "false") << endl;
    
    // Test case 6: Large numbers
    vector<int> nums6 = {100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100};
    cout << "Test 6: " << (solution.canPartition(nums6) ? "true" : "false") << endl;

    vector<int> nums7 = {2, 2, 1, 1};
    cout << "Test 7: " << (solution.canPartition(nums7) ? "true" : "false") << endl;
    
    return 0;
}
