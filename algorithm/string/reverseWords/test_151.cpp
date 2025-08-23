#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string reverseWords(string s)
    {
        if(!s.empty())
        {
            // 快慢双指针，整理词序
            size_t fast = 0;
            size_t low = 0;
            for(; fast < s.size(); fast++)
            {
                if(s[fast] != ' ')
                {
                    if(low != 0) s[low++] = ' ';
                    while(fast < s.size() && s[fast] != ' ')
                    {
                        s[low] = s[fast];
                        
                        fast ++;
                        low ++;
                    }
                }
            }

            // 双重反转，先整体反转，再逐个反转单词
            s.resize(low);
            reverse(s.begin(), s.begin() + low);

            size_t start = 0;
            size_t end = 0;
            for(; end <= s.size(); end++)
            {
                if(end == s.size() || s[end] == ' ')
                {
                    reverse(s.begin() + start, s.begin() + end);
                    start = end + 1;
                }
            }
        }

        return s;
    }
};


int main()
{
    Solution solution;
    string s = "  hello world  ";
    string result = solution.reverseWords(s);
    cout << result << endl;

    return 0;
}