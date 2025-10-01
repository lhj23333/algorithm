#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // int wiggleMaxLength(vector<int>& nums) {
    //     if(nums.size() == 0) return 0;
    //     int preDiff = 0;
    //     int curDiff = 0;
    //     int result = 1;

    //     for(size_t i = 0; i < nums.size() - 1; i ++) {
    //         curDiff = nums[i + 1] - nums[i];
    //         if(preDiff <= 0 && curDiff > 0 || preDiff >= 0 && curDiff < 0) {
    //             result ++;
    //             preDiff = curDiff;
    //         }
    //     }
    //     return result;
    // }

    int wiggleMaxLength(vector<int> &nums) {
        if(nums.size() < 2) return (int)nums.size();

        int up = 1;
        int down = 1;

        for(size_t i = 1; i < nums.size(); i++) {
            if(nums[i] > nums[i - 1]) up = down + 1;
            else if(nums[i] < nums[i - 1]) down = up + 1;
        }
        return max(up, down);
    }
};

static void printVec(const vector<int>& v) {
    cout << "[";
    for(size_t i = 0; i < v.size(); ++i) {
        if(i) cout << ", ";
        cout << v[i];
    }
    cout << "]";
}

void runTest(const vector<int>& nums, int expected, Solution& sol) {
    vector<int> data = nums; // copy for method
    int actual = sol.wiggleMaxLength(data);
    cout << "Input: ";
    printVec(nums);
    cout << " | Expected (正确结果): " << expected;
    cout << " | Actual: " << actual;
    cout << " | Result: " << (actual == expected ? "PASS" : "FAIL") << "\n";
}

int main()
{
    Solution sol;
    // More tests covering edge cases and typical cases
    runTest({}, 0, sol);
    runTest({1}, 1, sol);
    runTest({1, 1}, 1, sol);
    runTest({1, 2}, 2, sol);
    runTest({1, 7, 4, 9, 2, 5}, 6, sol);
    runTest({1, 17, 5, 10, 13, 15, 10, 5, 16, 8}, 7, sol);
    runTest({1, 2, 3, 4, 5, 6, 7, 8, 9}, 2, sol);
    runTest({3, 3, 3, 2, 5}, 3, sol);
    runTest({0, 0}, 1, sol);
    runTest({-1, -2, -3, -2, -1, 0}, 3, sol);

    return 0;
}