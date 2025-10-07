#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
private:
    int process(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;

        int maxSqrt = sqrt(n);
        for(size_t i = 1; i <= maxSqrt; i ++) {
            for(size_t j = i*i; j <= n; j ++) {
                dp[j] = min(dp[j], dp[j - i*i] + 1);
            }
        }
        return dp[n];
    }

public:
    int numSquares(int n) {
        return process(n);
    }
};

int main() {
    Solution solution;
    
    // Test basic cases
    cout << "Test 1 (n=1): " << solution.numSquares(1) << " (expected: 1)" << endl;
    cout << "Test 2 (n=4): " << solution.numSquares(4) << " (expected: 1)" << endl;
    cout << "Test 3 (n=12): " << solution.numSquares(12) << " (expected: 3)" << endl;
    cout << "Test 4 (n=13): " << solution.numSquares(13) << " (expected: 2)" << endl;
    
    // Test perfect squares
    cout << "Test 5 (n=9): " << solution.numSquares(9) << " (expected: 1)" << endl;
    cout << "Test 6 (n=16): " << solution.numSquares(16) << " (expected: 1)" << endl;
    cout << "Test 7 (n=25): " << solution.numSquares(25) << " (expected: 1)" << endl;
    
    // Test edge cases
    cout << "Test 8 (n=2): " << solution.numSquares(2) << " (expected: 2)" << endl;
    cout << "Test 9 (n=3): " << solution.numSquares(3) << " (expected: 3)" << endl;
    
    // Test larger numbers
    cout << "Test 10 (n=100): " << solution.numSquares(100) << " (expected: 1)" << endl;
    cout << "Test 11 (n=7): " << solution.numSquares(7) << " (expected: 4)" << endl;
    cout << "Test 12 (n=48): " << solution.numSquares(48) << " (expected: 3)" << endl;
    
    return 0;
}
