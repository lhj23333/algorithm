#include <iostream>

using namespace std;

int main() {
    long long l1, r1, l2, r2;
    cin >> l1 >> r1 >> l2 >> r2;

    // 计算最小和最大 (x + y) / 2
    long long min_sum = l1 + l2;
    long long max_sum = r1 + r2;
    long long min_mid = min_sum / 2;  // floor(min_sum / 2)
    long long max_mid = max_sum / 2;  // floor(max_sum / 2)

    // 不同值的数量
    cout << max_mid - min_mid + 1 << endl;
    return 0;
}
