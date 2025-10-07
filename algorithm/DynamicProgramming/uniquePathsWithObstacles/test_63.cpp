#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int process(vector<vector<int>> &obstacleGrid, size_t m, size_t n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = 1;

        for(size_t i = 0; i < m; i ++) {
            for(size_t j = 0; j < n; j ++) {
                if(obstacleGrid[i][j] == 1) continue;
                if(i > 0) dp[i][j] += dp[i - 1][j];
                if(j > 0) dp[i][j] += dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }

public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
        size_t m = obstacleGrid.size();
        size_t n = obstacleGrid[0].size();
        if(obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1) return 0;
        return process(obstacleGrid, m, n);
    }
};

void test(const vector<vector<int>>& grid, int expected) {
    Solution sol;
    vector<vector<int>> g = grid;
    int result = sol.uniquePathsWithObstacles(g);
    cout << "Result: " << result << ", Expected: " << expected << endl;
    cout << (result == expected ? "PASS" : "FAIL") << endl;
}

int main() {
    // Test 1: No obstacles, 3x3 grid
    test({{0,0,0},{0,0,0},{0,0,0}}, 6);

    // Test 2: Obstacle in the middle
    test({{0,0,0},{0,1,0},{0,0,0}}, 2);

    // Test 3: Obstacle at start
    test({{1,0,0},{0,0,0},{0,0,0}}, 0);

    // Test 4: Obstacle at end
    test({{0,0,0},{0,0,0},{0,0,1}}, 0);

    // Test 5: Single row, no obstacles
    test({{0,0,0,0}}, 1);

    // Test 6: Single column, no obstacles
    test({{0},{0},{0},{0}}, 1);

    // Test 7: Single cell, no obstacle
    test({{0}}, 1);

    // Test 8: Single cell, with obstacle
    test({{1}}, 0);

    // Test 9: All obstacles except start and end
    test({{0,1,1},{1,1,1},{1,1,0}}, 0);

    // Test 10: Path blocked in the middle row
    test({{0,0,0},{1,1,0},{0,0,0}}, 1);

    return 0;
}
