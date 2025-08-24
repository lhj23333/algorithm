#include <iostream>
#include <vector>

using namespace std;
class Solution {
private:
    // 构建 next 数组
    vector<size_t> getNext(const string& pattern)
    {
        if(pattern.empty()) return {};

        size_t lengthPattern = pattern.size();
        vector<size_t> next(lengthPattern, 0);
        
        size_t j = 0, i = 1;       // j: 当前next数组最长相等前后缀
                                   // i: 迭代新加入元素
        for(; i < lengthPattern; i++)
        {
            // 前后缀冲突
            while(j > 0 && pattern[i] != pattern[j]) j = next[j - 1];
            // 相等前后缀
            if(pattern[i] == pattern[j]) j ++;
            
            next[i] = j;
        }
        return next;
    }

public:
    vector<size_t> KMP(const string &text, const string &pattern)
    {
        if(text.empty()) return {};

        vector<size_t> next = getNext(pattern);
        vector<size_t> result;

        size_t j = 0, i = 0;       // j：模式串索引
                                   // i：文本串索引
        for(; i < text.size(); i++)
        {
            // 迭代配对冲突，遵循 KMP 算法回退之前最长相等前后缀原则
            while(j > 0 && text[i] != pattern[j]) j = next[j - 1];
            // 迭代配对成功
            if(text[i] == pattern[j]) j ++;

            // 完全配对成功
            if(j == pattern.size())
            {
                result.push_back(i - j + 1);
                
                // 迭代进行下一次检索
                j = next[j - 1];
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    string text = "abaababdabababd";
    string pattern = "ababd";
    vector<size_t> result = solution.KMP(text, pattern);

    for(size_t index : result)
    {
        cout << "Pattern found at index: " << index << endl;
    }
    return 0;
}