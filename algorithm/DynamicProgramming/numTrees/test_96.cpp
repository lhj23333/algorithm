#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
private:
    // 算法思路: 遍历dp，每一个新添加的数字 i，就相当于在树中新插入节点，即存在 i 种情况
    // 举例: 
    //      1. 当 i 为头节点时，则其种类为 dp[0] * dp[i - 1] 种；
    //      2. 当 i 为叶子节点时，则其种类为 dp[i - 1] * dp[0] 种;
    //      3. 当 i 为中间节点时，则其种类为 dp[j] + dp[i - 1 - j] 种；
    // 就相当于求 i 在插入过后，以其为划分的左节点数量与右节点数量的乘积和
    int process(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        
        for(size_t i = 2; i <= (size_t)n; i ++) {
            for(size_t j = 0; j < i; j ++) {
                dp[i] += dp[j] * dp[i - 1 - j];
            }
        }
        return dp[n];
    }

public:
    int numTrees(int n) {
        if(n < 2) return 1;
        return process(n);
    }
};

int main() {
    Solution solution;
    
    // Basic test cases
    assert(solution.numTrees(1) == 1);
    assert(solution.numTrees(2) == 2);
    assert(solution.numTrees(3) == 5);
    assert(solution.numTrees(4) == 14);
    assert(solution.numTrees(5) == 42);
    
    // Edge cases
    assert(solution.numTrees(0) == 1);
    
    // Additional test cases
    assert(solution.numTrees(6) == 132);
    assert(solution.numTrees(7) == 429);
    assert(solution.numTrees(8) == 1430);
    assert(solution.numTrees(9) == 4862);
    assert(solution.numTrees(10) == 16796);
    
    cout << "All tests passed!" << endl;
    return 0;
}
