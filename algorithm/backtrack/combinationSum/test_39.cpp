#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

class Solution {
private:
    vector<int> path;
    vector<vector<int>> result;

    void backtracking(vector<int> &candidates, int target, int start, int sum) {
        if(sum == target) {
            result.push_back(path);
            return;
        }

        for(size_t i = start; i < candidates.size(); i ++) {
            if(sum + candidates[i] > target) break;
            path.push_back(candidates[i]);
            backtracking(candidates, target, i, sum + candidates[i]);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        path.clear();
        result.clear();
        if(candidates.empty() || target < 1) return {};
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0, 0);
        return result;
    }
};

static void printVec(const vector<int>& v) {
    cout << "[";
    for(size_t i = 0; i < v.size(); ++i) {
        cout << v[i];
        if(i + 1 < v.size()) cout << ",";
    }
    cout << "]";
}

static void printVecVec(const vector<vector<int>>& vv) {
    cout << "[";
    for(size_t i = 0; i < vv.size(); ++i) {
        printVec(vv[i]);
        if(i + 1 < vv.size()) cout << ",";
    }
    cout << "]";
}

// Correct reference implementation for expected results (avoids permutations and duplicates)
static vector<vector<int>> correctCombinationSum(vector<int> candidates, int target) {
    vector<vector<int>> res;
    if(candidates.empty() || target < 1) return res;
    sort(candidates.begin(), candidates.end());
    candidates.erase(unique(candidates.begin(), candidates.end()), candidates.end());
    vector<int> path;
    function<void(int,int)> dfs = [&](int start, int remain) {
        if(remain == 0) {
            res.push_back(path);
            return;
        }
        for(int i = start; i < (int)candidates.size(); ++i) {
            int val = candidates[i];
            if(val > remain) break;
            path.push_back(val);
            dfs(i, remain - val); // allow reuse of same element
            path.pop_back();
        }
    };
    dfs(0, target);
    return res;
}

int main()
{
    vector<pair<vector<int>, int>> tests = {
        {{2,3,6,7}, 7},
        {{2,3,5}, 8},
        {{}, 7},
        {{2}, 1},
        {{8,7,4,3}, 11},
        {{2,4,3}, 8} // candidates contains duplicate entry to test dedup handling for expected
    };

    for(size_t i = 0; i < tests.size(); ++i) {
        auto candidates = tests[i].first;
        int target = tests[i].second;
        cout << "Test " << i+1 << " candidates=";
        printVec(candidates);
        cout << " target=" << target << "\n";

        // run given Solution (may produce permutations / duplicates)
        vector<int> inputForSolution = candidates; // Solution expects non-const ref
        Solution sol;
        auto actual = sol.combinationSum(inputForSolution, target);

        // compute correct expected result
        auto expected = correctCombinationSum(candidates, target);

        cout << "Result:   ";
        printVecVec(actual);
        cout << "\nExpected: ";
        printVecVec(expected);
        cout << "\n\n";
    }

    return 0;
}