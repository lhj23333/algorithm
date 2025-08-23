#include<iostream>

using namespace std;

class Solution {
public:
    // 思路：哈希表数组
    // 1. 统计字符串 s 中每个字符出现的次数
    // 2. 统计字符串 t 中每个字符出现的次数
    // 3. 比较两个哈希表数组是否相等
    bool isAnagram(string s, string t){
        if(s.size() != t.size()) return false;

        int hase[26] = {0};
        int strLen = s.size();
        
        // 统计字符串 s 中每个字符出现的次数
        for(int i = 0; i < strLen; i ++)
        {
            hase[s[i] - 'a'] ++;
        }

        // 统计字符串 t 中每个字符出现的次数
        for(int i = 0; i < strLen; i++)
        {
            hase[t[i] - 'a'] --;
        }
        
        // 比较两个哈希表数组是否相等
        for(int i = 0; i < 26; i++)
        {
            if(hase[i] != 0) return false;
        }
        return true;
    }
};

int main()
{
    string s = "anagram";
    string t = "nagaram";
    Solution solut;
    bool res = solut.isAnagram(s, t);
    if(res){
        cout << "true" << endl;
    }
    else{
        cout << "false" << endl;
    }
}