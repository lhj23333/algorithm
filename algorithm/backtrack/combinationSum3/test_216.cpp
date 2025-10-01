#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    int sum = 0;

    void backtracking(int k, int n, int startIndex) {
        if(path.size() == k && sum == n) {
            result.push_back(path);
            return;
        }

        // 剪枝操作：1. 组合内元素个数能否满足
        //          2. 当前 sum < targetSum
        for(int i = startIndex; i <= 9 - (k - path.size()) + 1 && sum < n; i ++) {
            path.push_back(i);
            sum += i;
            backtracking(k, n, i + 1); 
            sum -= i;
            path.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        path.clear();
        result.clear();
        if(k < 2 || k > 9 || n < 1) return {};

        backtracking(k, n, 1);

        return result;
    }
};

static void printVecVec(const vector<vector<int>>& v) {
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
    Solution sol;

    struct Test { int k; int n; vector<vector<int>> expected; };
    vector<Test> tests = {
        // Example 1
        {3, 7, {{1,2,4}}},
        // Example 2
        {3, 9, {{1,2,6},{1,3,5},{2,3,4}}},
        // Single number case (edge of allowed k normally is 1 for the problem)
        {1, 1, {{1}}},
        // No solution
        {3, 2, {}},
        // Multiple pairs
        {2, 9, {{1,8},{2,7},{3,6},{4,5}}},
        // Full 1..9 sum
        {9, 45, {{1,2,3,4,5,6,7,8,9}}}
    };

    for(const auto& t : tests) {
        auto res = sol.combinationSum3(t.k, t.n);
        cout << "Test k=" << t.k << " n=" << t.n << " Computed: ";
        printVecVec(res);
        cout << " Expected: ";
        printVecVec(t.expected);
        cout << "\n";
    }

    return 0;
}