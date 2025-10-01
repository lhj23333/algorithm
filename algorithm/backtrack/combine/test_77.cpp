#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<int> path;
    vector<vector<int>> result;

    void backtracking(int n, int k, int startIndex) {
        if(path.size() == k) {
            result.push_back(path);
            return;
        }
        for(int i = startIndex ; i <= n - (k - path.size()) + 1; i ++) {
            path.push_back(i);
            backtracking(n, k, i + 1);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> combine(int n, int k) {
        path.clear();
        result.clear();
        if(n <= 0 || k <= 0 || k > n) return {};
        backtracking(n, k, 1);
        return result;
    }
};

static void printVecVec(const vector<vector<int>>& v) {
    cout << "[";
    for(size_t i = 0; i < v.size(); ++i) {
        if(i) cout << ", ";
        cout << "[";
        for(size_t j = 0; j < v[i].size(); ++j) {
            if(j) cout << ", ";
            cout << v[i][j];
        }
        cout << "]";
    }
    cout << "]";
}

int main()
{
    Solution sol;

    struct Test { int n; int k; vector<vector<int>> expected; };
    vector<Test> tests = {
        {4, 2, {{1,2},{1,3},{1,4},{2,3},{2,4},{3,4}}},
        {1, 1, {{1}}},
        {4, 4, {{1,2,3,4}}},
        {4, 1, {{1},{2},{3},{4}}},
        {3, 5, {}}, // k > n -> empty
        {0, 0, {}}, // invalid -> empty
        {5, 3, {{1,2,3},{1,2,4},{1,2,5},{1,3,4},{1,3,5},{1,4,5},{2,3,4},{2,3,5},{2,4,5},{3,4,5}}}
    };

    for(size_t i = 0; i < tests.size(); ++i) {
        const auto &t = tests[i];
        auto out = sol.combine(t.n, t.k);
        cout << "Test " << (i+1) << " (n=" << t.n << ", k=" << t.k << ")\n";
        cout << "Output:   ";
        printVecVec(out);
        cout << "\nExpected: ";
        printVecVec(t.expected);
        cout << "\n\n";
    }

    return 0;
}