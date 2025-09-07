#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        if(tokens.empty()) return 0;
        stack<int> CalculateNumber;
        
        for(size_t i = 0; i < tokens.size(); i ++) {
            // 判断是否为数字
            if(tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/") {
                CalculateNumber.push(stoi(tokens[i]));
            } else {
                int a = CalculateNumber.top(); CalculateNumber.pop();
                int b = CalculateNumber.top(); CalculateNumber.pop();

                if(tokens[i] == "+") b += a;
                else if(tokens[i] == "-") b -= a;
                else if(tokens[i] == "*") b *= a;
                else if(tokens[i] == "/") b /= a;

                CalculateNumber.push(b);
            } 
        }
        return CalculateNumber.top();
    }
};

int main()
{
    Solution sol;

    // 测试用例1: 基本加法
    vector<string> tokens1 = {"2", "1", "+", "3", "*"};
    cout << "Test 1: " << sol.evalRPN(tokens1) << " (Expected: 9)" << endl;

    // 测试用例2: 包含除法
    vector<string> tokens2 = {"4", "13", "5", "/", "+"};
    cout << "Test 2: " << sol.evalRPN(tokens2) << " (Expected: 6)" << endl;

    // 测试用例3: 负数和减法
    vector<string> tokens3 = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    cout << "Test 3: " << sol.evalRPN(tokens3) << " (Expected: 22)" << endl;

    // 测试用例4: 单个数字
    vector<string> tokens4 = {"42"};
    cout << "Test 4: " << sol.evalRPN(tokens4) << " (Expected: 42)" << endl;

    // 测试用例5: 复杂表达式
    vector<string> tokens5 = {"3", "4", "+", "2", "*", "7", "/"};
    cout << "Test 5: " << sol.evalRPN(tokens5) << " (Expected: 2)" << endl;

    return 0;
}