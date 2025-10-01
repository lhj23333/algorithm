#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string process(string b, string a) {
        // 统计输入串b中每个字符的数量
        int count[26] = {0};
        for(char c : b) {
            count[c - 'A']++;
        }
        
        string result = "";
        
        // 第一步：按照顺序串a的顺序输出字符
        for(char c : a) {
            while(count[c - 'A'] > 0) {
                result += c;
                count[c - 'A']--;
            }
        }
        
        // 第二步：剩余字符按升序（A-Z）输出
        for(int i = 0; i < 26; i++) {
            while(count[i] > 0) {
                result += ('A' + i);
                count[i]--;
            }
        }
        
        return result;
    }
};

int main()
{
    Solution sol;
    
    string a, b;  // a为顺序串，b为输入串
    cin >> a >> b;
    
    cout << sol.process(b, a) << endl;
    
    return 0;
}
