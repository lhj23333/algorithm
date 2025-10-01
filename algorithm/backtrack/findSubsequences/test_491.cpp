#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <functional>

using namespace std;

class Solution {
private:
    vector<int> path;
    vector<vector<int>> result;

    void backtracking(vector<int> &nums, size_t startIndex) {
        if(path.size() > 1) {
            result.push_back(path);
        }

        unordered_set<int> used;
        for(size_t i = startIndex; i < nums.size(); i ++) {
            if(used.count(nums[i])) continue;                   // 避免单层重复元素遍历
            // if(i > startIndex && nums[i] == nums[i - 1])     // 避免单层连续重复元素遍历
            if(path.empty() || nums[i] >= path.back()) {
                used.insert(nums[i]);
                path.push_back(nums[i]);
                backtracking(nums, i + 1);
                path.pop_back();
            } 
        }
    }

public:
    vector<vector<int>> findSubsequences(vector<int> &nums) {
        path.clear();
        result.clear();
        if(nums.empty()) return {};
        backtracking(nums, 0);
        return result;
    }
};

// Correct reference implementation to produce expected results
vector<vector<int>> correctFindSubsequences(const vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> path;
    function<void(int)> dfs = [&](int start) {
        if(path.size() >= 2) res.push_back(path);
        unordered_set<int> used;
        for(int i = start; i < (int)nums.size(); ++i) {
            if(used.count(nums[i])) continue;
            if(path.empty() || nums[i] >= path.back()) {
                used.insert(nums[i]);
                path.push_back(nums[i]);
                dfs(i + 1);
                path.pop_back();
            }
        }
    };
    dfs(0);
    return res;
}

void printVecVec(const vector<vector<int>>& v) {
    cout << "[";
    for(size_t i = 0; i < v.size(); ++i) {
        cout << "[";
        for(size_t j = 0; j < v[i].size(); ++j) {
            cout << v[i][j];
            if(j + 1 < v[i].size()) cout << ",";
        }
        cout << "]";
        if(i + 1 < v.size()) cout << ",";
    }
    cout << "]";
}

int main()
{
    vector<vector<int>> tests = {
        {},                    // empty
        {4,6,7,7},             // example with duplicates
        {4,4,3,2,1},           // mostly decreasing with a duplicate pair
        {1,1,1},               // all equal
        {1,2,1,1,1,1}
    };

    Solution sol;
    for(size_t i = 0; i < tests.size(); ++i) {
        vector<int> input = tests[i];
        cout << "Case " << i+1 << " Input: ";
        cout << "[";
        for(size_t k=0;k<input.size();++k){
            cout << input[k];
            if(k+1<input.size()) cout << ",";
        }
        cout << "]\n";

        vector<vector<int>> output = sol.findSubsequences(input);
        cout << "Output: ";
        printVecVec(output);
        cout << "\n";

        vector<vector<int>> expected = correctFindSubsequences(input);
        cout << "Expected: ";
        printVecVec(expected);
        cout << "\n\n";
    }

    return 0;
}