#include <iostream>
#include <vector>

using namespace std;

class Soluiton {
private:
    int process(vector<string> &strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for(string str: strs) {
            int numOne = 0;
            int numZero = 0;     
            for(char c: str) {
                if(c == '0') numZero ++;
                else numOne ++;
            } 

            for(int i = m; i >= numZero; i --) {
                for(int j = n; j >= numOne; j --) {
                    dp[i][j] = max(dp[i][j], dp[i - numZero][j - numOne] + 1);
                }
            }
        }
        return dp[m][n];
    }

public:
    int findMaxForm(vector<string> &strs, int m, int n) {
        return process(strs, m, n);
    }
};

int main() {
    Soluiton sol;
    
    // Test case 1: Basic example
    vector<string> strs1 = {"10", "0001", "111001", "1", "0"};
    cout << "Test 1: " << sol.findMaxForm(strs1, 5, 3) << endl; // Expected: 4
    
    // Test case 2: Edge case - empty array
    vector<string> strs2 = {};
    cout << "Test 2: " << sol.findMaxForm(strs2, 1, 1) << endl; // Expected: 0
    
    // Test case 3: Edge case - m=0, n=0
    vector<string> strs3 = {"10", "01"};
    cout << "Test 3: " << sol.findMaxForm(strs3, 0, 0) << endl; // Expected: 0
    
    // Test case 4: Only zeros
    vector<string> strs4 = {"00", "000", "0000"};
    cout << "Test 4: " << sol.findMaxForm(strs4, 10, 0) << endl; // Expected: 3
    
    // Test case 5: Only ones
    vector<string> strs5 = {"11", "111", "1111"};
    cout << "Test 5: " << sol.findMaxForm(strs5, 0, 10) << endl; // Expected: 3
    
    // Test case 6: Single string that fits
    vector<string> strs6 = {"101"};
    cout << "Test 6: " << sol.findMaxForm(strs6, 1, 2) << endl; // Expected: 1
    
    // Test case 7: Single string that doesn't fit
    vector<string> strs7 = {"1010"};
    cout << "Test 7: " << sol.findMaxForm(strs7, 1, 1) << endl; // Expected: 0
    
    return 0;
}
