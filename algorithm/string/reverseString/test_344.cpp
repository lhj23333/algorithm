#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 算法思路：
    // 1. 使用双指针法，左指针指向字符串开头，右指针指向字符串结尾
    // 2. 交换左右指针指向的字符，然后移动指针
    // 3. 重复步骤2，直到左右指针相遇
    void reverseString(vector<char>& s)
    {
        if(!s.empty())
        {
            size_t indexLeft = 0;
            size_t indexRight = s.size() - 1;

            while(indexRight > indexLeft)
            {
                swap(s[indexLeft++], s[indexRight--]);
            }
        }
    }
};

int main()
{
    Solution solution;
    vector<char> s = {'h', 'e', 'l', 'l', 'o'};
    solution.reverseString(s);

    for(char c : s)
        cout << c << " ";
    cout << endl;

    return 0;
}