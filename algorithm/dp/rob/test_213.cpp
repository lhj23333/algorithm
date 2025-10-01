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
    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return max(nums[0], nums[1]);

        vector<int> nums1(nums.begin(), nums.end() - 1);
        vector<int> nums2(nums.begin() + 1, nums.end());

        return max(process(nums1), process(nums2));
    }
};

int main() {
    Solution solution;
    
    // Test case 1: Basic circular array
    vector<int> nums1 = {2, 3, 2};
    cout << "Test 1 - [2,3,2]: " << solution.rob(nums1) << " (expected: 3)" << endl;
    
    // Test case 2: Larger circular array
    vector<int> nums2 = {1, 2, 3, 1};
    cout << "Test 2 - [1,2,3,1]: " << solution.rob(nums2) << " (expected: 4)" << endl;
    
    // Test case 3: Single house
    vector<int> nums3 = {5};
    cout << "Test 3 - [5]: " << solution.rob(nums3) << " (expected: 5)" << endl;
    
    // Test case 4: Two houses
    vector<int> nums4 = {1, 2};
    cout << "Test 4 - [1,2]: " << solution.rob(nums4) << " (expected: 2)" << endl;
    
    // Test case 5: All same values
    vector<int> nums5 = {5, 5, 5, 5, 5};
    cout << "Test 5 - [5,5,5,5,5]: " << solution.rob(nums5) << " (expected: 10)" << endl;
    
    // Test case 6: Increasing values
    vector<int> nums6 = {1, 2, 3, 4, 5, 6};
    cout << "Test 6 - [1,2,3,4,5,6]: " << solution.rob(nums6) << " (expected: 12)" << endl;
    
    // Test case 7: Large first and last elements
    vector<int> nums7 = {10, 1, 1, 1, 10};
    cout << "Test 7 - [10,1,1,1,10]: " << solution.rob(nums7) << " (expected: 12)" << endl;
    
    return 0;
}
