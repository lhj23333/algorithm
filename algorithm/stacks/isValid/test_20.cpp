#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    bool isValid(string s)
    {        
        stack<char> st;
        for(size_t i = 0; i < s.size(); i++)
         {
            // 左括号：压入其对应的右括号
            if(s[i] == '{' || s[i] == '(' || s[i] == '[') 
            {
                if(s[i] == '{') st.push('}');
                else if(s[i] == '(') st.push(')');
                else st.push(']');
            } 
            // 右括号：检查匹配
            else if(s[i] == '}' || s[i] == ')' || s[i] == ']')
            {
                if(st.empty() || s[i] != st.top()) return false;
                st.pop();
            }
        }
    
        return st.empty();
    }
};

int main()
{
Solution solution;
    // 测试用例：{输入字符串, 期望结果}
    vector<pair<string, bool>> testCases = {
        // 基本有效情况
        {"()", true},
        {"[]", true},
        {"{}", true},
        {"()[]{}", true},
        {"([{}])", true},
        
        // 基本无效情况
        {"(]", false},
        {"([)]", false},
        {"((", false},
        {"))", false},
        
        // 复杂有效情况
        {"({[]})", true},
        {"((()))", true},
        {"[[[]]]{{{}}}", true},
        {"(()())", true},
        
        // 复杂无效情况
        {"([)]", false},
        {"((]", false},
        {"{[}", false},
        {"}{", false},
        
        // 边界情况
        {"", true},           // 空字符串
        {"(", false},         // 单个左括号
        {")", false},         // 单个右括号
        {"abc", true},        // 无括号字符（如果要忽略非括号字符）
        
        // 混合字符情况（如果需要处理）
        {"a(b)c", true},
        {"a(b]c", false},
    };
    
    cout << "=== 括号匹配测试 ===\n";
    cout << "格式: [测试序号] 输入 -> 结果 (期望)\n\n";
    
    int passed = 0;
    for (size_t i = 0; i < testCases.size(); i++) {
        string input = testCases[i].first;
        bool expected = testCases[i].second;
        bool result = solution.isValid(input);
        
        cout << "[" << i + 1 << "] \"" << input << "\" -> ";
        
        if (result == expected) {
            cout << "✓ PASS";
            passed++;
        } else {
            cout << "✗ FAIL";
        }
        
        cout << " (期望: " << (expected ? "有效" : "无效") 
             << ", 实际: " << (result ? "有效" : "无效") << ")\n";
    }
    
    cout << "\n=== 测试结果 ===\n";
    cout << "通过: " << passed << "/" << testCases.size() << " 个测试\n";
    
    if (passed == testCases.size()) {
        cout << "🎉 所有测试通过！\n";
    } else {
        cout << "❌ 部分测试失败，请检查代码逻辑。\n";
    }
    
    // 交互式测试
    cout << "\n=== 交互式测试 ===\n";
    cout << "输入括号字符串进行测试 (输入 'quit' 退出):\n";
    
    string userInput;
    while (true) {
        cout << "请输入: ";
        getline(cin, userInput);
        
        if (userInput == "quit") break;
        
        bool result = solution.isValid(userInput);
        cout << "结果: \"" << userInput << "\" -> " 
             << (result ? "有效" : "无效") << "\n\n";
    }
    
    return 0;
}