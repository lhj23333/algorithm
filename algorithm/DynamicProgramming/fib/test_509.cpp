#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int process(int n) {
        vector<int> dp(n + 1);

        dp[0] = 0;
        dp[1] = 1;
        for(size_t i = 2; i <= n; i ++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }

public:
    int fib(int n) {
        if(n < 2) return n;
        return process(n);
    }
};

int main() {
    Solution solution;
    
    // Test base cases
    cout << "fib(0) = " << solution.fib(0) << " (expected: 0)" << endl;
    cout << "fib(1) = " << solution.fib(1) << " (expected: 1)" << endl;
    
    // Test small numbers
    cout << "fib(2) = " << solution.fib(2) << " (expected: 1)" << endl;
    cout << "fib(3) = " << solution.fib(3) << " (expected: 2)" << endl;
    cout << "fib(4) = " << solution.fib(4) << " (expected: 3)" << endl;
    cout << "fib(5) = " << solution.fib(5) << " (expected: 5)" << endl;
    
    // Test medium numbers
    cout << "fib(10) = " << solution.fib(10) << " (expected: 55)" << endl;
    cout << "fib(15) = " << solution.fib(15) << " (expected: 610)" << endl;
    cout << "fib(20) = " << solution.fib(20) << " (expected: 6765)" << endl;
    
    return 0;
}

