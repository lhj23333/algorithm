#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    int process(int m, int n, vector<int> &weight, vector<int> &value, vector<int> nums){
        vector<int> dp(m + 1, 0);

        for(int i = 0; i < n; i ++) {
            for(int j = m; j >= weight[i]; j --) {
                for(int k = 1; j >= k * weight[i] && k <= nums[i]; k ++) {
                    dp[j] = max(dp[j], dp[j - k * weight[i]] + k * value[i]);
                }
            }
        }
        return dp[m];
    }

public:
    int carryOreResource(int m, int n, vector<int> &weight, vector<int> &value, vector<int> nums) {
        return process(m, n, weight, value, nums);
    }
};

int main() {
    int m;  // 背包大小
    int n;  // 物品数量
    cin >> m >> n;

    vector<int> weight(n, 0);
    vector<int> value(n, 0);
    vector<int> nums(n, 0);
    for(size_t i = 0; i < n; i ++) cin >> weight[i];
    for(size_t i = 0; i < n; i ++) cin >> value[i];
    for(size_t i = 0; i < n; i ++) cin >> nums[i];

    Solution sol;
    cout << sol.carryOreResource(m, n, weight, value, nums) << endl;
}