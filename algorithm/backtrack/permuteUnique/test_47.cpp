#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
private:
    vector<int> path;
    vector<vector<int>> result;

    void backtracking(vector<int> &nums, size_t startIndex) {
        if(path.size() == nums.size()) {
            result.push_back(path);
            return ;
        }

        unordered_set<int> set;
        for(size_t i = startIndex; i < nums.size(); i ++) {
            if(set.count(nums[i])) continue;
            set.insert(nums[i]);
            path.push_back(nums[i]);
            swap(nums[i], nums[startIndex]);
            backtracking(nums, startIndex + 1);
            swap(nums[i], nums[startIndex]);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int> &nums) {
        path.clear();
        result.clear();
        if(nums.empty()) return {};
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

static void printVecVec(const vector<vector<int>>& vv) {
    cout << "[";
    for(size_t i = 0; i < vv.size(); ++i) {
        if(i) cout << ",";
        printVec(vv[i]);
    }
    cout << "]";
}

int main()
{
    Solution sol;

    vector<vector<int>> tests = {
        {},                      // empty
        {1},                     // single
        {1,1,2},                 // duplicatessolveNQueens
        {1,2,3},                 // distinct
        {1,1,2,2}                // more duplicates
    };

    vector<vector<vector<int>>> expect = {
        {}, // expected for empty input: no permutations per current API
        {{1}},
        {{1,1,2},{1,2,1},{2,1,1}},
        {{1,2,3},{1,3,2},{2,1,3},{2,3,1},{3,1,2},{3,2,1}},
        {{1,1,2,2},{1,2,1,2},{1,2,2,1},{2,1,1,2},{2,1,2,1},{2,2,1,1}}
    };

    for(size_t i = 0; i < tests.size(); ++i) {
        auto input = tests[i];
        cout << "Test " << i+1 << " - input: ";
        printVec(input);
        cout << "\nOutput:   ";
        auto out = sol.permuteUnique(input);
        printVecVec(out);
        cout << "\nExpected: ";
        printVecVec(expect[i]);
        cout << "\n\n";
    }

    return 0;
}