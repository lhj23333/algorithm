#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int process(vector<int> &nums) {
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for(size_t i = 2; i < nums.size(); i ++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        return dp[nums.size() - 1];
    }

public:
    int rob(vector<int> &nums) {
        if(nums.empty()) return 0;
        if(nums.size() == 1) return nums[0];
        return process(nums);
    }
};

int main() {
    Solution sol;

    // Test 1: Basic case
    vector<int> nums1 = {1, 2, 3, 1};
    cout << "Test 1: " << sol.rob(nums1) << " (Expected: 4)" << endl;

    // Test 2: All houses have the same amount
    vector<int> nums2 = {2, 2, 2, 2};
    cout << "Test 2: " << sol.rob(nums2) << " (Expected: 4)" << endl;

    // Test 3: Only one house
    vector<int> nums3 = {5};
    cout << "Test 3: " << sol.rob(nums3) << " (Expected: 5)" << endl;

    // Test 4: Two houses
    vector<int> nums4 = {2, 7};
    cout << "Test 4: " << sol.rob(nums4) << " (Expected: 7)" << endl;

    // Test 5: Empty input
    vector<int> nums5 = {};
    cout << "Test 5: " << sol.rob(nums5) << " (Expected: 0)" << endl;

    // Test 6: Large values
    vector<int> nums6 = {100, 1, 1, 100};
    cout << "Test 6: " << sol.rob(nums6) << " (Expected: 200)" << endl;

    // Test 7: Increasing values
    vector<int> nums7 = {1, 2, 3, 4, 5};
    cout << "Test 7: " << sol.rob(nums7) << " (Expected: 9)" << endl;

    // Test 8: Decreasing values
    vector<int> nums8 = {5, 4, 3, 2, 1};
    cout << "Test 8: " << sol.rob(nums8) << " (Expected: 9)" << endl;

    return 0;
}
