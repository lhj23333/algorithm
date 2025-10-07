#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int process(vector<int> &nums, int len) {
        vector<int> dp(len, 1);
        int result = INT_MIN;

        for(int i = 1; i < len; i ++) {
            if(nums[i] > nums[i - 1]) dp[i] = dp[i - 1] + 1;
            result = max(result, dp[i]);
        }
        return result;
    }

public:
    int findLengthOfLCIS(vector<int> &nums) {
        int len = nums.size();
        if(len < 2) return len;
        return process(nums, len);
    }
};

int main() {
    Solution solution;
    
    // Test case 1: Normal increasing sequence
    vector<int> nums1 = {1, 3, 6, 7, 9, 4, 10, 5, 6, 8, 15};
    cout << "Test 1: " << solution.findLengthOfLCIS(nums1) << endl; // Expected: 5
    
    // Test case 2: Strictly decreasing sequence
    vector<int> nums2 = {2, 2, 2, 2, 2};
    cout << "Test 2: " << solution.findLengthOfLCIS(nums2) << endl; // Expected: 1
    
    // Test case 3: Single element
    vector<int> nums3 = {5};
    cout << "Test 3: " << solution.findLengthOfLCIS(nums3) << endl; // Expected: 1
    
    // Test case 4: Empty array
    vector<int> nums4 = {};
    cout << "Test 4: " << solution.findLengthOfLCIS(nums4) << endl; // Expected: 0
    
    // Test case 5: Two elements increasing
    vector<int> nums5 = {1, 2};
    cout << "Test 5: " << solution.findLengthOfLCIS(nums5) << endl; // Expected: 2
    
    // Test case 6: Two elements decreasing
    vector<int> nums6 = {3, 1};
    cout << "Test 6: " << solution.findLengthOfLCIS(nums6) << endl; // Expected: 1
    
    // Test case 7: All increasing
    vector<int> nums7 = {1, 2, 3, 4, 5};
    cout << "Test 7: " << solution.findLengthOfLCIS(nums7) << endl; // Expected: 5
    
    return 0;
}
