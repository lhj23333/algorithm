#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

    class Solution {
    public:
        string removeDuplicates(string s) {
            if(s.empty()) return {};        
            stack<char> st;
            string result;
            
            for(size_t i = 0; i < s.size(); i ++) {
                if(!st.empty() && s[i] == st.top()) st.pop();
                else st.push(s[i]);
            }

            while(!st.empty()) {
                result += st.top();
                st.pop();
            }
            reverse(result.begin(), result.end());

            return result;
        }    
    };

int main()
{
    Solution sln;
    string s = "abbaca";
    cout << sln.removeDuplicates(s) << endl;
}