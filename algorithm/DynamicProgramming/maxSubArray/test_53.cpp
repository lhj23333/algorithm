#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int process(vector<int> &nums) {
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];

        int result = dp[0];
        for(int i = 1; i < nums.size(); i ++) {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            result = max(dp[i], result);
        }
        return result;
    }

public:
    int maxSubArray(vector<int> &nums) {
        if(nums.size() == 0) return 0;
        return process(nums);
    }
};

int main() {
    Solution solution;
    
    // Test case 1: Basic case with mixed positive and negative numbers
    vector<int> nums1 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "Test 1: " << solution.maxSubArray(nums1) << " (expected: 6)" << endl;
    
    // Test case 2: All negative numbers
    vector<int> nums2 = {-3, -2, -1, -4};
    cout << "Test 2: " << solution.maxSubArray(nums2) << " (expected: -1)" << endl;
    
    // Test case 3: All positive numbers
    vector<int> nums3 = {1, 2, 3, 4, 5};
    cout << "Test 3: " << solution.maxSubArray(nums3) << " (expected: 15)" << endl;
    
    // Test case 4: Single element
    vector<int> nums4 = {5};
    cout << "Test 4: " << solution.maxSubArray(nums4) << " (expected: 5)" << endl;
    
    // Test case 5: Single negative element
    vector<int> nums5 = {-1};
    cout << "Test 5: " << solution.maxSubArray(nums5) << " (expected: -1)" << endl;
    
    // Test case 6: Two elements
    vector<int> nums6 = {-1, 2};
    cout << "Test 6: " << solution.maxSubArray(nums6) << " (expected: 2)" << endl;
    
    // Test case 7: Alternating pattern
    vector<int> nums7 = {1, -1, 1, -1, 1};
    cout << "Test 7: " << solution.maxSubArray(nums7) << " (expected: 1)" << endl;
    
    return 0;
}
