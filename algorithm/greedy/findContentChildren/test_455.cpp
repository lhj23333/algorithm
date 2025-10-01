#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:

    int process(vector<int> &g, vector<int> &n) {
        int cnt = 0;
        for(size_t i = 0, j = 0; i < g.size() && j < n.size(); ){
            if (n[j] >= g[i]) {
                i ++; j ++; cnt ++;
            } else {
                j ++;
            }
        }
        return cnt;
    }

public:
    int findContentChildren(vector<int> &g, vector<int> &n) {
        if(g.empty() || n.empty()) return 0;
        sort(g.begin(), g.end());
        sort(n.begin(), n.end());
        return process(g, n);
    }
};

int correctExpected(vector<int> g, vector<int> s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int i = 0, j = 0, cnt = 0;
    while (i < (int)g.size() && j < (int)s.size()) {
        if (s[j] >= g[i]) { cnt++; i++; j++; }
        else { j++; }
    }
    return cnt;
}

int main()
{
    Solution sol;

    vector<pair<vector<int>, vector<int>>> tests = {
        // Basic examples
        {{1,2,3}, {1,1}},
        {{1,2}, {1,2,3}},
        // Edge cases: empty
        {{}, {1,2}},
        {{1,1,1}, {}},
        // Larger cookies than needs
        {{10,9,8,7}, {5,6,7,8}},
        // Single big cookie
        {{1,2,3,4}, {10}},
        // Case that exposes the bug in the provided implementation
        {{2,3,4}, {1,1,7}},
        // All zeros
        {{0,0,0}, {0}}
    };

    for (size_t i = 0; i < tests.size(); ++i) {
        auto g = tests[i].first;
        auto s = tests[i].second;
        auto g_copy = g;
        auto s_copy = s;

        int result = sol.findContentChildren(g_copy, s_copy);
        int expected = correctExpected(g, s);

        cout << "Test " << (i+1) << " - Result: " << result << " Expected: " << expected << '\n';
    }

    return 0;
}