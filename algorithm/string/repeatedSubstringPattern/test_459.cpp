#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    vector<size_t> getNext(string &pattern)
    {
        if(pattern.empty()) return {};

        vector<size_t> next(pattern.size(), 0);
        size_t j = 0, i = 1;

        for(; i < pattern.size(); i ++)
        {
            while(j > 0 && pattern[i] != pattern[j]) j = next[j - 1];
            if(pattern[i] == pattern[j]) j ++;

            next[i] = j;
        }

        return next;
    }

public:
    // 算法思路：移动匹配：
    //          将字符串与自身拼接，形成一个新的字符串
    //          然后在新字符串去除首尾元素，可查找到原字符串 -> 该字符串可由子串重复构成
    bool repeatedSubstringPattern(string s)
    {
        if (s.empty()) return false;
        vector<size_t> next = getNext(s);
        string ss = s + s;

        // 1. KMP 匹配搜索
        size_t j = 0;
        for(size_t i = 1; i < ss.size() - 1; i ++)
        {
            while(j > 0 && ss[i] != s[j]) j = next[j - 1];
            if(ss[i] == s[j]) j ++;

            if(j == s.size())
            {
                return true;
            }
        }

        // 2. 库函数匹配搜索
        ss.erase(ss.size() - 1);
        if(ss.find(s, 1) != string::npos)
            return true;
            
        return false;
    }
};

int main()
{
    Solution solut;
    
    // 测试用例
    vector<string> testCases = {
        "abab",     // true: "ab" + "ab"
        "aba",      // false: 无法由重复子串组成
        "abcabcabcabc", // true: "abc" + "abc" + "abc" + "abc"
        "ababc",    // false: 无法由重复子串组成
        "a",        // false: 单字符无法重复
        "aa",       // true: "a" + "a"
        "aaa"       // true: "a" + "a" + "a"
    };
    
    for(const string& s : testCases) {
        bool res = solut.repeatedSubstringPattern(s);
        cout << "\"" << s << "\": " << (res ? "true" : "false") << endl;
    }
    
    return 0;
}