#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    int process(int n) {
        vector<int> dp(n + 1);
        dp[2] = 1;

        for(int i = 3; i <= n; i++) {
            for(int j = 1; j <= i / 2; j++) {
                // j * i - j : 双项；
                // dp[i - j] * j : 双项向下拆分
                dp[i] = max(dp[i], max(j * (i - j), dp[i - j] * j));
            }
        }
        return dp[n];
    }

public:
    int integerBreak(int n) {
        return process(n);
    }
};

void test(Solution& sol, int n, int expected) {
    int result = sol.integerBreak(n);
    cout << "integerBreak(" << n << ") = " << result
         << " | Expected: " << expected
         << " | " << (result == expected ? "PASS" : "FAIL") << endl;
}

int main() {
    Solution sol;
    test(sol, 2, 1);    // 1+1
    test(sol, 3, 2);    // 2+1
    test(sol, 4, 4);    // 2+2
    test(sol, 5, 6);    // 2+3
    test(sol, 6, 9);    // 3+3
    test(sol, 7, 12);   // 3+4
    test(sol, 8, 18);   // 3+3+2
    test(sol, 9, 27);   // 3+3+3
    test(sol, 10, 36);  // 3+3+4
    test(sol, 15, 243); // 3*3*3*3*3
    test(sol, 20, 1458);// 3^6*2
    return 0;
}
