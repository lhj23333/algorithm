#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int process(int n, int m) {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;

        for(size_t i = 0; i <= n; i ++) {
            for(size_t j = 1; j <= m; j ++) {
                if(i >= j) dp[i] += dp[i - j];
            }
        }
        return dp[n];
    }

public:
    int climbStairsPlus(int n, int m) {
        if(n < 2) return 1;
        return process(n, m);
    }
};

void test_climbStairsPlus() {
    Solution sol;

    // Test 1: n = 4, m = 2 (classic climb stairs)
    cout << "Test 1: " << (sol.climbStairsPlus(4, 2) == 5 ? "Passed" : "Failed") << endl;

    // Test 2: n = 5, m = 2
    cout << "Test 2: " << (sol.climbStairsPlus(5, 2) == 8 ? "Passed" : "Failed") << endl;

    // Test 3: n = 4, m = 3
    cout << "Test 3: " << (sol.climbStairsPlus(4, 3) == 7 ? "Passed" : "Failed") << endl;

    // Test 4: n = 0, m = 2 (edge case)
    cout << "Test 4: " << (sol.climbStairsPlus(0, 2) == 1 ? "Passed" : "Failed") << endl;

    // Test 5: n = 1, m = 2 (edge case)
    cout << "Test 5: " << (sol.climbStairsPlus(1, 2) == 1 ? "Passed" : "Failed") << endl;

    // Test 6: n = 6, m = 3
    cout << "Test 6: " << (sol.climbStairsPlus(6, 3) == 24 ? "Passed" : "Failed") << endl;

    // Test 7: n = 10, m = 2
    cout << "Test 7: " << (sol.climbStairsPlus(10, 2) == 89 ? "Passed" : "Failed") << endl;

    // Test 8: n = 3, m = 1 (only one way)
    cout << "Test 8: " << (sol.climbStairsPlus(3, 1) == 1 ? "Passed" : "Failed") << endl;
}

int main() {
    test_climbStairsPlus();
    return 0;
}
