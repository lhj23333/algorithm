#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int q;
    cin >> q;
    for (int query = 0; query < q; ++query) {
        string s;
        cin >> s;
        int n = s.length();
        if (n < 3) {
            // 对于长度小于3的字符串，没有长度3的子串，直接替换'?'为'r'
            for (char &c : s) {
                if (c == '?') c = 'r';
            }
            cout << s << endl;
            continue;
        }
        // 分成三个组
        vector<string> group(3);
        for (int i = 0; i < n; ++i) {
            group[i % 3] += s[i];
        }
        // 确定每个组的字符
        vector<char> chars(3, 0);
        vector<bool> fixed(3, false);
        bool possible = true;
        for (int k = 0; k < 3; ++k) {
            set<char> seen;
            for (char c : group[k]) {
                if (c != '?') seen.insert(c);
            }
            if (seen.size() > 1) {
                possible = false;
                break;
            }
            if (seen.size() == 1) {
                chars[k] = *seen.begin();
                fixed[k] = true;
            }
        }
        if (!possible) {
            cout << "No" << endl;
            continue;
        }
        // 现在，处理固定
        set<char> available = {'r', 'e', 'd'};
        vector<char> assigned(3, 0);
        // 移除已固定的
        for (int k = 0; k < 3; ++k) {
            if (fixed[k]) {
                available.erase(chars[k]);
                assigned[k] = chars[k];
            }
        }
        // 如果有冲突
        if (available.size() < 3 - count(fixed.begin(), fixed.end(), true)) {
            possible = false;
        } else {
            // 分配剩余的
            auto it = available.begin();
            for (int k = 0; k < 3; ++k) {
                if (!fixed[k]) {
                    assigned[k] = *it;
                    ++it;
                }
            }
        }
        if (!possible) {
            cout << "No" << endl;
            continue;
        }
        // 填充字符串
        string result = s;
        for (int i = 0; i < n; ++i) {
            if (result[i] == '?') {
                result[i] = assigned[i % 3];
            }
        }
        // 验证（虽然理论上应该正确）
        bool valid = true;
        for (int i = 0; i <= n - 3; ++i) {
            set<char> sub = {result[i], result[i+1], result[i+2]};
            if (sub.size() != 3) {
                valid = false;
                break;
            }
        }
        if (valid) {
            cout << result << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}