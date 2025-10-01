#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
private:
    vector<int> path;
    vector<vector<int>> result;
    // unordered_set<int> set;

    // // 1. 暴力
    // void backtracking(vector<int> &nums) {
    //     if(path.size() == nums.size()){
    //         result.push_back(path);
    //         return ;
    //     }

    //     for(size_t i = 0; i < nums.size(); i ++) {
    //         if(set.count(nums[i])) continue;
    //         path.push_back(nums[i]);
    //         set.insert(nums[i]);
    //         backtracking(nums);
    //         set.erase(nums[i]);
    //         path.pop_back();
    //     }
    // }

    // 2. 技巧剪枝
    void backtracking(vector<int> &nums, size_t startIndex) {
        if(path.size() == nums.size()) {
            result.push_back(path);
            return ;
        }

        for(size_t i = startIndex; i < nums.size(); i++) {
            path.push_back(nums[i]);
            swap(nums[i], nums[startIndex]);
            backtracking(nums, startIndex + 1);
            swap(nums[i], nums[startIndex]);
            path.pop_back();     
        }
    }

public:
    vector<vector<int>> permute(vector<int> &nums) {
        path.clear();
        result.clear();
        if(nums.empty()) return {};
        // backtracking(nums);
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

static void printMatrix(const vector<vector<int>>& m) {
    cout << "[";
    for(size_t i = 0; i < m.size(); ++i) {
        if(i) cout << ",";
        printVec(m[i]);
    }
    cout << "]\n";
}

int main()
{
    Solution sol;

    vector<vector<int>> inputs;
    inputs.push_back(vector<int>{1,2,3});
    inputs.push_back(vector<int>{0,1});
    inputs.push_back(vector<int>{1});
    inputs.push_back(vector<int>{}); // empty input

    vector<vector<vector<int>>> expecteds;
    expecteds.push_back(vector<vector<int>>{
        {1,2,3},{1,3,2},{2,1,3},{2,3,1},{3,1,2},{3,2,1}
    });
    expecteds.push_back(vector<vector<int>>{
        {0,1},{1,0}
    });
    expecteds.push_back(vector<vector<int>>{
        {1}
    });
    expecteds.push_back(vector<vector<int>>{}); // expected empty

    for(size_t i = 0; i < inputs.size(); ++i) {
        vector<int> input = inputs[i]; // permute requires non-const reference
        cout << "Test " << i+1 << " input: ";
        printVec(input);
        cout << "\nResult: ";
        vector<vector<int>> result = sol.permute(input);
        printMatrix(result);
        cout << "Expected: ";
        printMatrix(expecteds[i]);
        cout << "-----\n";
    }

    return 0;
}