#include <iostream>
#include <vector>
#include <cstdint>

using namespace std;

class Solution {
private:
    // int result;

    // void backtraving(string s, string t, int sIndex, int tIndex) {
    //     if(tIndex == t.size()) {
    //         result ++;
    //         return;
    //     }

    //     for(int i = sIndex; i < s.size(); i ++) {
    //         if(s[i] == t[tIndex]) backtraving(s, t, i + 1, tIndex + 1);
    //     }
    // }

        int process(string s, string t) {
            vector<vector<uint64_t>> dp(s.size() + 1, vector<uint64_t>(t.size() + 1, 0));
            for(int i = 0; i <= s.size(); i++) dp[i][0] = 1;
            for(int i = 1; i <= t.size(); i++) dp[0][i] = 0;

            for(int i = 1; i <= s.size(); i ++) {
                for(int j = 1; j <= t.size(); j ++) {
                    if(s[i - 1] == t[j - 1]) dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                    else dp[i][j] = dp[i - 1][j];
                }
            }
            return dp[s.size()][t.size()];
        }

public:
    int numDistinct(string s, string t) {
        // result = 0;
        // backtraving(s, t, 0, 0);
        // return result;
        return process(s, t);
    }
};

int main() {
    Solution solution;
    
    // Test case 1: Basic example
    string s1 = "rabbbit", t1 = "rabbit";
    cout << "Test 1: s=\"" << s1 << "\", t=\"" << t1 << "\" -> " << solution.numDistinct(s1, t1) << endl;
    
    // Test case 2: Single character
    string s2 = "b", t2 = "a";
    cout << "Test 2: s=\"" << s2 << "\", t=\"" << t2 << "\" -> " << solution.numDistinct(s2, t2) << endl;
    
    // Test case 3: Empty target
    string s3 = "abc", t3 = "";
    cout << "Test 3: s=\"" << s3 << "\", t=\"" << t3 << "\" -> " << solution.numDistinct(s3, t3) << endl;
    
    // Test case 4: Multiple occurrences
    string s4 = "babgbag", t4 = "bag";
    cout << "Test 4: s=\"" << s4 << "\", t=\"" << t4 << "\" -> " << solution.numDistinct(s4, t4) << endl;
    
    // Test case 5: No match
    string s5 = "abc", t5 = "def";
    cout << "Test 5: s=\"" << s5 << "\", t=\"" << t5 << "\" -> " << solution.numDistinct(s5, t5) << endl;
    
    // Test case 6: Same strings
    string s6 = "abc", t6 = "abc";
    cout << "Test 6: s=\"" << s6 << "\", t=\"" << t6 << "\" -> " << solution.numDistinct(s6, t6) << endl;
    
    return 0;
}
