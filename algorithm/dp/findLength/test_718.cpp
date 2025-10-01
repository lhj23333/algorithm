#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int process(vector<int> &nums1, vector<int> &nums2) {
        vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size() + 1, 0));
        int result = 0;

        for (int i = 1; i <= nums1.size(); i++) {
            for (int j = 1; j <= nums2.size(); j++) {
                if (nums1[i - 1] == nums2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                if (dp[i][j] > result) result = dp[i][j];
            }
        }
        return result;
    }

public:
    int findLength(vector<int> &nums1, vector<int> &nums2) {
        if(nums1.size() == 0 || nums2.size() == 0) return 0;
        return process(nums1, nums2);
    }
};

int main() {
    Solution solution;
    
    // Test case 1: Basic example
    vector<int> nums1_1 = {1, 2, 3, 2, 1};
    vector<int> nums2_1 = {3, 2, 1, 4, 7};
    cout << "Test 1: " << solution.findLength(nums1_1, nums2_1) << " (expected: 3)" << endl;
    
    // Test case 2: No common subarray
    vector<int> nums1_2 = {1, 2, 3};
    vector<int> nums2_2 = {4, 5, 6};
    cout << "Test 2: " << solution.findLength(nums1_2, nums2_2) << " (expected: 0)" << endl;
    
    // Test case 3: Empty arrays
    vector<int> nums1_3 = {};
    vector<int> nums2_3 = {1, 2, 3};
    cout << "Test 3: " << solution.findLength(nums1_3, nums2_3) << " (expected: 0)" << endl;
    
    // Test case 4: Identical arrays
    vector<int> nums1_4 = {1, 2, 3};
    vector<int> nums2_4 = {1, 2, 3};
    cout << "Test 4: " << solution.findLength(nums1_4, nums2_4) << " (expected: 3)" << endl;
    
    // Test case 5: Single element arrays
    vector<int> nums1_5 = {5};
    vector<int> nums2_5 = {5};
    cout << "Test 5: " << solution.findLength(nums1_5, nums2_5) << " (expected: 1)" << endl;
    
    // Test case 6: Common subarray at the beginning
    vector<int> nums1_6 = {1, 2, 3, 8, 9};
    vector<int> nums2_6 = {1, 2, 3, 4, 5};
    cout << "Test 6: " << solution.findLength(nums1_6, nums2_6) << " (expected: 3)" << endl;
    
    // Test case 7: Common subarray at the end
    vector<int> nums1_7 = {7, 8, 1, 2, 3};
    vector<int> nums2_7 = {4, 5, 1, 2, 3};
    cout << "Test 7: " << solution.findLength(nums1_7, nums2_7) << " (expected: 3)" << endl;
    
    vector<int> nums1_8 = {0, 1, 1, 1, 1};
    vector<int> nums2_8 = {1, 0, 1, 0, 1};
    cout << "Test 8: " << solution.findLength(nums1_8, nums2_8) << " (expected: 2)" << endl;

    return 0;
}
