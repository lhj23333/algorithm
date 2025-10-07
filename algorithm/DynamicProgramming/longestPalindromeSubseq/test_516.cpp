#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int process(string s) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
        for (int i = 0; i < s.size(); i++) dp[i][i] = 1;

        for(int i = s.size(); i >= 0; i --) {
            for(int j = i + 1; j < s.size(); j ++) {
                if(s[i] == s[j]) dp[i][j] = dp[i + 1][j - 1] + 2;
                else dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
        return dp[0][s.size() - 1];
    }

public:
    int longestPalindromeSubseq(string s) {
        if(s.size() < 2) return s.size();
        return process(s);
    }
};

int main() {
    Solution solution;
    
    // Test 1: Simple palindrome
    cout << "Test 1: " << solution.longestPalindromeSubseq("bbbab") << endl; // Expected: 4
    
    // Test 2: No palindrome longer than 1
    cout << "Test 2: " << solution.longestPalindromeSubseq("cbbd") << endl; // Expected: 2
    
    // Test 3: Single character
    cout << "Test 3: " << solution.longestPalindromeSubseq("a") << endl; // Expected: 1
    
    // Test 4: Empty string
    cout << "Test 4: " << solution.longestPalindromeSubseq("") << endl; // Expected: 0
    
    // Test 5: All same characters
    cout << "Test 5: " << solution.longestPalindromeSubseq("aaaa") << endl; // Expected: 4
    
    // Test 6: Entire string is palindrome
    cout << "Test 6: " << solution.longestPalindromeSubseq("racecar") << endl; // Expected: 7
    
    // Test 7: Longer string
    cout << "Test 7: " << solution.longestPalindromeSubseq("euazbipzncptldueeuechubrcourfpftcebikrxhybkymimgvldiwqvkszfycvqyvtiwfckexmowcxztkfyzqovbtmzpxojfofbvwnncajvrvdbvjhcrameamcfmcoxryjukhpljwszknhiypvyskmsujkuggpztltpgoczafmfelahqwjbhxtjmebnymdyxoeodqmvkxittxjnlltmoobsgzdfhismogqfpfhvqnxeuosjqqalvwhsidgiavcatjjgeztrjuoixxxoznklcxolgpuktirmduxdywwlbikaqkqajzbsjvdgjcnbtfksqhquiwnwflkldgdrqrnwmshdpykicozfowmumzeuznolmgjlltypyufpzjpuvucmesnnrwppheizkapovoloneaxpfinaontwtdqsdvzmqlgkdxlbeguackbdkftzbnynmcejtwudocemcfnuzbttcoew") << endl; // Expected: 159
    
    // Test 8: Two characters same
    cout << "Test 8: " << solution.longestPalindromeSubseq("aa") << endl; // Expected: 2
    
    // Test 9: Two characters different
    cout << "Test 9: " << solution.longestPalindromeSubseq("ab") << endl; // Expected: 1
    
    // Test 10: Alternating pattern
    cout << "Test 10: " << solution.longestPalindromeSubseq("ababababa") << endl; // Expected: 9
    
    return 0;
}
