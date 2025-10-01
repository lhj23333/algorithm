#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    vector<int> path;
    vector<vector<int>> result;

    void backtracking(vector<int> &nums, size_t startIndex) {
        result.push_back(path);

        for(size_t i = startIndex; i < nums.size(); i ++) {
            if(i > startIndex && nums[i] == nums[i - 1]) continue;
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        path.clear();
        result.clear();
        if(nums.empty()) return {};
        sort(nums.begin(), nums.end());
        backtracking(nums, 0);
        return result;
    }
};

static void printVec(const vector<int>& v) {
    cout << "[";
    for(size_t i = 0; i < v.size(); ++i) {
        if(i) cout << ",";
        cout << v[i];
    }
    cout << "]";
}

static void printVecs(const vector<vector<int>>& vv) {
    cout << "{";
    for(size_t i = 0; i < vv.size(); ++i) {
        if(i) cout << ", ";
        printVec(vv[i]);
    }
    cout << "}";
}

static void runTest(const vector<int>& input, const vector<vector<int>>& expected) {
    Solution sol;
    vector<int> nums = input;
    auto result = sol.subsetsWithDup(nums);

    cout << "Input: ";
    printVec(input);
    cout << "\nResult: ";
    printVecs(result);
    cout << "\nExpected: ";
    printVecs(expected);
    cout << "\n\n";
}

int main()
{
    // Tests covering empty, single, duplicates, and mixed cases.

    // 1) empty input
    runTest({}, { {} }); // correct expected: one subset, the empty subset

    // 2) single element
    runTest({1}, { {}, {1} });

    // 3) simple duplicate case
    runTest({1,2,2}, { {}, {1}, {1,2}, {1,2,2}, {2}, {2,2} });

    // 4) all duplicates
    runTest({2,2,2}, { {}, {2}, {2,2}, {2,2,2} });

    // 5) no duplicates (three elements)
    runTest({1,2,3}, { {}, {1}, {1,2}, {1,2,3}, {1,3}, {2}, {2,3}, {3} });

    return 0;
}