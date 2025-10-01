#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int process(int m, int n) {
        int dp[m][n];
        for(size_t i = 1; i < m; i ++) dp[i][0] = 1;
        for(size_t i = 1; i < n; i ++) dp[0][i] = 1;

        for(size_t i = 1; i < m; i ++) {
            for(size_t j = 1; j < n; j ++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }

public:
    int uniquePaths(int m, int n) {
        if(m == 1 && n == 1) return 1;
        return process(m, n);
    }
};

void test_uniquePaths() {
    Solution sol;

    // Test 1: 3x7 grid
    cout << "Test 1 (3x7): " << (sol.uniquePaths(3, 7) == 28 ? "Passed" : "Failed") << endl;

    // Test 2: 3x2 grid
    cout << "Test 2 (3x2): " << (sol.uniquePaths(3, 2) == 3 ? "Passed" : "Failed") << endl;

    // Test 3: 7x3 grid
    cout << "Test 3 (7x3): " << (sol.uniquePaths(7, 3) == 28 ? "Passed" : "Failed") << endl;

    // Test 4: 3x3 grid
    cout << "Test 4 (3x3): " << (sol.uniquePaths(3, 3) == 6 ? "Passed" : "Failed") << endl;

    // Test 5: 1x1 grid
    cout << "Test 5 (1x1): " << (sol.uniquePaths(1, 1) == 1 ? "Passed" : "Failed") << endl;

    // Test 6: 1x5 grid
    cout << "Test 6 (1x5): " << (sol.uniquePaths(1, 5) == 1 ? "Passed" : "Failed") << endl;

    // Test 7: 5x1 grid
    cout << "Test 7 (5x1): " << (sol.uniquePaths(5, 1) == 1 ? "Passed" : "Failed") << endl;

    // Test 8: 10x10 grid
    cout << "Test 8 (10x10): " << (sol.uniquePaths(10, 10) == 48620 ? "Passed" : "Failed") << endl;
}

int main() {
    test_uniquePaths();
    return 0;
}
