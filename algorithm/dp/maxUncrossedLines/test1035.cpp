#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int process(vector<int> &nums1, vector<int> &nums2) {
        vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size() + 1, 0));

        for(int i = 1; i <= nums1.size(); i ++) {
            for(int j = 1; j <= nums2.size(); j ++) {
                if(nums1[i - 1] == nums2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[nums1.size()][nums2.size()];
    }

public:
    int maxUncrossedLines(vector<int> &nums1, vector<int> &nums2) {
        if(nums1.size() == 0 || nums2.size() == 0) return 0;
        return process(nums1, nums2);
    }
};

int main() {
    Solution sol;

    // Test 1: Basic example
    vector<int> nums1_1 = {1, 4, 2};
    vector<int> nums2_1 = {1, 2, 4};
    cout << "Test 1: " << sol.maxUncrossedLines(nums1_1, nums2_1) << endl; // Expected: 2

    // Test 2: Example from problem
    vector<int> nums1_2 = {2, 5, 1, 2, 5};
    vector<int> nums2_2 = {10, 5, 2, 1, 5, 2};
    cout << "Test 2: " << sol.maxUncrossedLines(nums1_2, nums2_2) << endl; // Expected: 3

    // Test 3: Another example
    vector<int> nums1_3 = {1, 3, 7, 1, 7, 5};
    vector<int> nums2_3 = {1, 9, 2, 5, 1};
    cout << "Test 3: " << sol.maxUncrossedLines(nums1_3, nums2_3) << endl; // Expected: 2

    // Test 4: No common elements
    vector<int> nums1_4 = {1, 2, 3};
    vector<int> nums2_4 = {4, 5, 6};
    cout << "Test 4: " << sol.maxUncrossedLines(nums1_4, nums2_4) << endl; // Expected: 0

    // Test 5: One array is empty
    vector<int> nums1_5 = {};
    vector<int> nums2_5 = {1, 2, 3};
    cout << "Test 5: " << sol.maxUncrossedLines(nums1_5, nums2_5) << endl; // Expected: 0

    // Test 6: Single element arrays with match
    vector<int> nums1_6 = {5};
    vector<int> nums2_6 = {5};
    cout << "Test 6: " << sol.maxUncrossedLines(nums1_6, nums2_6) << endl; // Expected: 1

    // Test 7: Single element arrays without match
    vector<int> nums1_7 = {3};
    vector<int> nums2_7 = {7};
    cout << "Test 7: " << sol.maxUncrossedLines(nums1_7, nums2_7) << endl; // Expected: 0

    // Test 8: All elements the same
    vector<int> nums1_8 = {1, 1, 1};
    vector<int> nums2_8 = {1, 1, 1};
    cout << "Test 8: " << sol.maxUncrossedLines(nums1_8, nums2_8) << endl; // Expected: 3

    return 0;
}

