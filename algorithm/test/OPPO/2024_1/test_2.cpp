#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; ++t) {
        int n;
        cin >> n;
        vector<vector<int>> A(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> A[i][j];
            }
        }
        vector<vector<int>> B(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> B[i][j];
            }
        }
        int min_ops = INT_MAX;
        bool possible = false;
        // 枚举所有可能的行翻转：2^n 种可能性
        for (int mask = 0; mask < (1 << n); ++mask) {
            // 创建A的副本
            vector<vector<int>> A_copy = A;
            int row_flips = 0;
            // 应用行翻转
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    row_flips++;
                    for (int j = 0; j < n; ++j) {
                        A_copy[i][j] ^= 1;
                    }
                }
            }
            // 现在，检查列
            int col_flips = 0;
            // 模拟列翻转
            vector<vector<int>> A_final = A_copy;
            for (int j = 0; j < n; ++j) {
                bool need_flip = false;
                for (int i = 0; i < n; ++i) {
                    if (A_final[i][j] != B[i][j]) {
                        need_flip = true;
                        break;
                    }
                }
                if (need_flip) {
                    col_flips++;
                    for (int i = 0; i < n; ++i) {
                        A_final[i][j] ^= 1;
                    }
                }
            }
            // 检查是否相等
            bool equal = true;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (A_final[i][j] != B[i][j]) {
                        equal = false;
                        break;
                    }
                }
                if (!equal) break;
            }
            if (equal) {
                possible = true;
                min_ops = min(min_ops, row_flips + col_flips);
            }
        }
        if (possible) {
            cout << min_ops << endl;
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}