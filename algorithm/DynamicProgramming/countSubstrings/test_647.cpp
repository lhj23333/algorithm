#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
    bool isVaild(string s) {
        for(int i = 0; i < s.size()/2; i ++) {
            if(s[i] != s[s.size() - 1 - i]) return false;
        }
        return true;
    }

    int backtraving(string s) {
        int cnt = 0;

        for(int i = 0; i < s.size(); i ++) {
            for(int j = i; j < s.size(); j ++) {
                string str = s.substr(i, j - i + 1);
                if(isVaild(str)) cnt++;
            }
        }
        return cnt;
    }

    int process(string s) {
        int result = 0;
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        
        for(int i = s.size() - 1; i >= 0; i --) {
            for(int j = i; j < s.size(); j ++) {
                if(s[i] == s[j]) {
                    if(j - i <= 1) {
                        result ++;
                        dp[i][j] = true;
                    }
                    else if(dp[i + 1][j - 1]) {
                        result ++;
                        dp[i][j] = true;
                    }
                }
            }
        }
        return result;
    }
  
public:
    int countSubstrings(string s) {
        if(s.size() == 0) return 0;
        // return process(s);        
        return backtraving(s);;
    }
};

int main() {
    Solution solution;
    
    // Test 1: Single character
    cout << "Test 1: " << solution.countSubstrings("a") << " (Expected: 1)" << endl;
    
    // Test 2: All same characters
    cout << "Test 2: " << solution.countSubstrings("aaa") << " (Expected: 6)" << endl;
    
    // Test 3: Simple palindrome
    cout << "Test 3: " << solution.countSubstrings("abc") << " (Expected: 3)" << endl;
    
    // Test 4: Mixed palindromes
    cout << "Test 4: " << solution.countSubstrings("aabaa") << " (Expected: 9)" << endl;
    
    // Test 5: Longer string with palindromes
    cout << "Test 5: " << solution.countSubstrings("racecar") << " (Expected: 10)" << endl;
    
    // Test 6: Two characters same
    cout << "Test 6: " << solution.countSubstrings("aa") << " (Expected: 3)" << endl;
    
    // Test 7: Two characters different
    cout << "Test 7: " << solution.countSubstrings("ab") << " (Expected: 2)" << endl;
    
    // Test 8: Empty string
    cout << "Test 8: " << solution.countSubstrings("") << " (Expected: 0)" << endl;
    
    // Test 9: All different characters
    cout << "Test 9: " << solution.countSubstrings("abcd") << " (Expected: 4)" << endl;
    
    return 0;
}

