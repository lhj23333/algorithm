#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 构建 Next 数组（前缀表）
vector<int> buildNext(const string &pattern) {
    int n = pattern.size();
    vector<int> next(n, 0);
    int j = 0;               // 已匹配的前后缀长度

    for (int i = 1; i < n; i++) {
        while (j > 0 && pattern[i] != pattern[j]) {
            j = next[j - 1]; // 回退到之前的最长相等前后缀
        }
        if (pattern[i] == pattern[j]) {
            j++;
        }
        next[i] = j;
    }
    return next;
}

// KMP 匹配
vector<int> KMP(const string &text, const string &pattern) {
    vector<int> next = buildNext(pattern);
    vector<int> res;
    int j = 0; // 模式串指针

    for (int i = 0; i < (int)text.size(); i++) {
        while (j > 0 && text[i] != pattern[j]) {
            j = next[j - 1];
        }
        if (text[i] == pattern[j]) {
            j++;
        }
        if (j == (int)pattern.size()) {
            res.push_back(i - j + 1); // 记录匹配起始位置
            j = next[j - 1];          // 继续寻找下一个匹配
        }
    }
    return res;
}

int main() {
    string text = "ababcabcacbab";
    string pattern = "abcac";
    
    vector<int> positions = KMP(text, pattern);
    if (!positions.empty()) {
        cout << "Pattern found at positions: ";
        for (int pos : positions) cout << pos << " ";
        cout << endl;
    } else {
        cout << "Pattern not found." << endl;
    }
    return 0;
}
