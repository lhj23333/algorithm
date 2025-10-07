#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int process(int n) {
        vector<int> dp(n + 1);
        dp[1] = 1;
        dp[2] = 2;

        for(size_t i = 3; i <= n; i ++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
public:
    int climbStairs(int n) {
        if(n < 2) return n;
        return process(n);
    }
};

int main() {
    Solution solution;
    
    // Test cases
    cout << "Test 1 (n=1): " << solution.climbStairs(1) << " (expected: 1)" << endl;
    cout << "Test 2 (n=2): " << solution.climbStairs(2) << " (expected: 2)" << endl;
    cout << "Test 3 (n=3): " << solution.climbStairs(3) << " (expected: 3)" << endl;
    cout << "Test 4 (n=4): " << solution.climbStairs(4) << " (expected: 5)" << endl;
    cout << "Test 5 (n=5): " << solution.climbStairs(5) << " (expected: 8)" << endl;
    cout << "Test 6 (n=0): " << solution.climbStairs(0) << " (expected: 0)" << endl;
    cout << "Test 7 (n=-1): " << solution.climbStairs(-1) << " (expected: 0)" << endl;
    
    return 0;
}
