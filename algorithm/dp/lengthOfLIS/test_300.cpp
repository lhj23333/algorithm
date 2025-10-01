#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int maxLen;

    // // 1. 回溯暴力超时
    // void backtraving(vector<int> &nums, int startIndex, int len) {
    //     maxLen = max(maxLen, len);

    //     for(size_t i = startIndex; i < nums.size(); i++) {
    //         if(startIndex == 0) backtraving(nums, i + 1, len + 1);
    //         else {
    //             if(nums[i] > nums[startIndex - 1]) backtraving(nums, i + 1, len + 1);
    //         }
    //     }
    // }


    int process(vector<int> &nums) {
        int len = nums.size();
        int result = INT_MIN;
        vector<int> dp(len, 1);
        
        for(int i = 1; i < len; i ++) {
            for(int j = 0; j < i; j ++) {
                if(nums[i] > nums[j]) dp[i] = max(dp[i], dp[j] + 1);
            }
            result = max(result, dp[i]);
        }
        return result;
    }

public:    
    int lengthOfLIS(vector<int> &nums){
        if(nums.size() < 2) return nums.size();
        // maxLen = 1;
        // backtraving(nums, 0, 0);
        // return maxLen;
        return process(nums);
    }
};

int main() {
    Solution solution;
    
    // Test case 1: Basic increasing sequence
    vector<int> nums1 = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << "Test 1: " << solution.lengthOfLIS(nums1) << " (expected: 4)" << endl;
    
    // Test case 2: Strictly decreasing sequence
    vector<int> nums2 = {7, 7, 7, 7, 7, 7, 7};
    cout << "Test 2: " << solution.lengthOfLIS(nums2) << " (expected: 1)" << endl;
    
    // Test case 3: Single element
    vector<int> nums3 = {5};
    cout << "Test 3: " << solution.lengthOfLIS(nums3) << " (expected: 1)" << endl;
    
    // Test case 4: Two elements increasing
    vector<int> nums4 = {1, 3};
    cout << "Test 4: " << solution.lengthOfLIS(nums4) << " (expected: 2)" << endl;
    
    // Test case 5: Two elements decreasing
    vector<int> nums5 = {3, 1};
    cout << "Test 5: " << solution.lengthOfLIS(nums5) << " (expected: 1)" << endl;
    
    // Test case 6: Already sorted ascending
    vector<int> nums6 = {1, 2, 3, 4, 5};
    cout << "Test 6: " << solution.lengthOfLIS(nums6) << " (expected: 5)" << endl;
    
    // Test case 7: All same elements
    vector<int> nums7 = {2, 2, 2, 2};
    cout << "Test 7: " << solution.lengthOfLIS(nums7) << " (expected: 1)" << endl;
    
    // Test case 8: Complex case
    vector<int> nums8 = {0, 1, 0, 3, 2, 3};
    cout << "Test 8: " << solution.lengthOfLIS(nums8) << " (expected: 4)" << endl;
    
    return 0;
}
