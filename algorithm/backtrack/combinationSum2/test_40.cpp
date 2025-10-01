#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    vector<int> path;
    vector<vector<int>> result;

    void backtracking(vector<int> &candidates, int target, size_t startIndex, int sum) {
        if(sum == target) {
            result.push_back(path);
            return ;
        }

        for(size_t i = startIndex; i < candidates.size(); i ++) {
            if (i > startIndex && candidates[i] == candidates[i-1]) continue;   // 跳过同层相同元素，避免重复组合
            if(sum + candidates[i] > target) break;
            path.push_back(candidates[i]);
            backtracking(candidates, target, i + 1, sum + candidates[i]);       // 注意不对 i 进行处理哦
            path.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        path.clear();
        result.clear();
        if(candidates.empty() || target < 1) return {};
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0, 0);
        return result;
    }
};

static void printVecVec(const vector<vector<int>>& v) {
    cout << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        if (i) cout << ",";
        cout << "[";
        for (size_t j = 0; j < v[i].size(); ++j) {
            if (j) cout << ",";
            cout << v[i][j];
        }
        cout << "]";
    }
    cout << "]";
}

static void printVec(const vector<int>& v) {
    cout << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        if (i) cout << ",";
        cout << v[i];
    }
    cout << "]";
}

int main()
{
    Solution sol;

    // Test 1: example with duplicates
    {
        vector<int> candidates = {10,1,2,7,6,1,5};
        int target = 8;
        cout << "Test 1: candidates = ";
        printVec(candidates);
        cout << ", target = " << target << "\n";
        auto output = sol.combinationSum2(candidates, target);
        cout << "Output:   ";
        printVecVec(output);
        cout << "\nExpected: ";
        vector<vector<int>> expected = {{1,1,6},{1,2,5},{1,7},{2,6}};
        printVecVec(expected);
        cout << "\n\n";
    }

    // Test 2: another example with repeats
    {
        vector<int> candidates = {2,5,2,1,2};
        int target = 5;
        cout << "Test 2: candidates = ";
        printVec(candidates);
        cout << ", target = " << target << "\n";
        auto output = sol.combinationSum2(candidates, target);
        cout << "Output:   ";
        printVecVec(output);
        cout << "\nExpected: ";
        vector<vector<int>> expected = {{1,2,2},{5}};
        printVecVec(expected);
        cout << "\n\n";
    }

    // Test 3: empty candidates
    {
        vector<int> candidates = {};
        int target = 3;
        cout << "Test 3: candidates = ";
        printVec(candidates);
        cout << ", target = " << target << "\n";
        auto output = sol.combinationSum2(candidates, target);
        cout << "Output:   ";
        printVecVec(output);
        cout << "\nExpected: ";
        vector<vector<int>> expected = {};
        printVecVec(expected);
        cout << "\n\n";
    }

    // Test 4: all elements same
    {
        vector<int> candidates = {1,1,1,1};
        int target = 2;
        cout << "Test 4: candidates = ";
        printVec(candidates);
        cout << ", target = " << target << "\n";
        auto output = sol.combinationSum2(candidates, target);
        cout << "Output:   ";
        printVecVec(output);
        cout << "\nExpected: ";
        vector<vector<int>> expected = {{1,1}};
        printVecVec(expected);
        cout << "\n\n";
    }

    // Test 5: no solution
    {
        vector<int> candidates = {3,4,5};
        int target = 2;
        cout << "Test 5: candidates = ";
        printVec(candidates);
        cout << ", target = " << target << "\n";
        auto output = sol.combinationSum2(candidates, target);
        cout << "Output:   ";
        printVecVec(output);
        cout << "\nExpected: ";
        vector<vector<int>> expected = {};
        printVecVec(expected);
        cout << "\n\n";
    }

    return 0;
}