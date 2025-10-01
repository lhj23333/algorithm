#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<int> path;
    vector<vector<int>> result;

    void backtracking(vector<int> &nums, size_t startIndex){
        result.push_back(path);

        for(size_t i = startIndex; i < nums.size(); i ++) {
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> subsets(vector<int> &nums) {
        path.clear();
        result.clear();
        if(nums.empty()) return {};
        backtracking(nums, 0);
        return result;
    }
};

static void printVec(const vector<int>& v){
    cout << "[";
    for(size_t i=0;i<v.size();++i){
        if(i) cout << ",";
        cout << v[i];
    }
    cout << "]";
}

static void printVecVec(const vector<vector<int>>& vv){
    cout << "[";
    for(size_t i=0;i<vv.size();++i){
        if(i) cout << ",";
        printVec(vv[i]);
    }
    cout << "]";
}

static vector<vector<int>> expectedSubsets(const vector<int>& nums){
    vector<vector<int>> res;
    size_t n = nums.size();
    size_t total = 1ull << n;
    for(size_t mask = 0; mask < total; ++mask){
        vector<int> subset;
        for(size_t i=0;i<n;++i){
            if(mask & (1ull<<i)) subset.push_back(nums[i]);
        }
        res.push_back(subset);
    }
    return res;
}

int main()
{
    vector<vector<int>> tests = {
        {1,2,3},
        {0},
        {1,2},
        {} // include empty input to show behavior
    };

    Solution sol;
    for(size_t t=0;t<tests.size();++t){
        auto nums = tests[t];
        cout << "Test " << t+1 << " input: ";
        printVec(nums);
        cout << "\n";

        auto result = sol.subsets(nums);
        cout << "Result:   ";
        printVecVec(result);
        cout << "\n";

        auto expected = expectedSubsets(nums);
        cout << "Expected: ";
        printVecVec(expected);
        cout << "\n\n";
    }

    return 0;
}