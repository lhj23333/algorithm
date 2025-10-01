#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int combinationSum4(vector<int> &nums, int target) {
        vector<int> dp(target + 1, 0);
        dp[0] = 1;

        for(size_t i = 0; i <= target; i ++) {
            for(size_t j = 0; j < nums.size(); j ++) {
                if(i - nums[j] >= 0) {
                    dp[i] += dp[i - nums[j]];
                }
            }
        }
        return dp[target];
    }
};

int main() {
    Solution solution;
    
    // Test case 1: Basic example
    vector<int> nums1 = {1, 2, 3};
    int target1 = 4;
    cout << "Test 1 - nums: [1,2,3], target: 4, result: " << solution.combinationSum4(nums1, target1) << endl;
    
    // Test case 2: Single element
    vector<int> nums2 = {9};
    int target2 = 3;
    cout << "Test 2 - nums: [9], target: 3, result: " << solution.combinationSum4(nums2, target2) << endl;
    
    // Test case 3: Target is 0
    vector<int> nums3 = {1, 2};
    int target3 = 0;
    cout << "Test 3 - nums: [1,2], target: 0, result: " << solution.combinationSum4(nums3, target3) << endl;
    
    // Test case 4: Larger numbers
    vector<int> nums4 = {2, 1, 3};
    int target4 = 35;
    cout << "Test 4 - nums: [2,1,3], target: 35, result: " << solution.combinationSum4(nums4, target4) << endl;
    
    // Test case 5: Multiple same elements
    vector<int> nums5 = {1, 1, 1};
    int target5 = 3;
    cout << "Test 5 - nums: [1,1,1], target: 3, result: " << solution.combinationSum4(nums5, target5) << endl;
    
    return 0;
}
