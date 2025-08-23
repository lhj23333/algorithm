#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    // 算法思路：逻辑理解
    //          题意理解：每2k个字符为一组，前k个字符反转，后k个字符保持不变
    string reverseStr(string s, int k)
    {
        int lengthStr = s.size();

        for(int i = 0; i < lengthStr; i += 2 * k)
        {
            int end = min(i + k, lengthStr);

            reverse(s.begin() + i, s.begin() + end);
        }
        return s;
    }
};

int main()
{
    Solution solution;
    string s = "abcdefghijklmnop";
    int k = 2;
    string result = solution.reverseStr(s, k);
    cout << result << endl;

    return 0;
}
