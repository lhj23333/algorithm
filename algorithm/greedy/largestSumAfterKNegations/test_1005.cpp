#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <functional>

using namespace std;

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        int result = 0;
        sort(nums.begin(), nums.end());
        for(size_t i = 0; i < nums.size(); i ++) {
            if (nums[i] < 0 && k > 0) {
                nums[i] *= -1;
                k --;
            }
        }
        if(k % 2 == 1) {
            sort(nums.begin(), nums.end());
            nums[0] *= -1;
        }
        for(size_t i = 0; i < nums.size(); i ++) result += nums[i];
        return result;
    }
};

int bruteLargestSumAfterKNegations(vector<int> nums, int k) {
    int best = INT_MIN;
    function<void(int)> dfs = [&](int rem) {
        if (rem == 0) {
            int s = 0;
            for (int v : nums) s += v;
            best = max(best, s);
            return;
        }
        for (size_t i = 0; i < nums.size(); ++i) {
            nums[i] = -nums[i];
            dfs(rem - 1);
            nums[i] = -nums[i];
        }
    };
    dfs(k);
    return best;
}

void printVec(const vector<int>& v) {
    cout << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        if (i) cout << ", ";
        cout << v[i];
    }
    cout << "]";
}

int main()
{
    Solution sol;
    vector<pair<vector<int>, int>> tests = {
        {{4, 2, 3}, 1},
        {{3, -1, 0, 2}, 3},
        {{-2, -3, 4}, 1},        // order-sensitive case
        {{0, 0, 0}, 5},
        {{-2, 5, 0, -1, 3}, 4},
        {{2, -3, -1, 5, -4}, 2}
    };

    for (size_t i = 0; i < tests.size(); ++i) {
        vector<int> nums = tests[i].first;
        int k = tests[i].second;
        int expected = bruteLargestSumAfterKNegations(nums, k);
        vector<int> numsCopy = nums;
        int got = sol.largestSumAfterKNegations(numsCopy, k);
        cout << "Test " << (i+1) << ": nums=";
        printVec(tests[i].first);
        cout << ", k=" << k << " -> Expected: " << expected << ", Got: " << got << "\n";
    }

    return 0;
}