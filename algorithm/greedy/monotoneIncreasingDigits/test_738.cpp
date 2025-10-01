#include <iostream>
#include <string>

using namespace std;

class Solution {
private:
    int process(int n) {
        if(n < 10) return n;
        string str = to_string(n);

        size_t mark = str.size();
        for(size_t i = str.size() - 1; i > 0; i --) {
            if(str[i] < str[i - 1]) { 
                mark = i;
                str[i - 1] --;
            }
        }
        for(size_t i = mark; i < str.size(); i++) {
            str[i] = '9';
        }
        return stoi(str);
    }

public:
    int monotoneIncreasingDigits(int n) {
        return process(n);
    }
};

int main() {
    Solution solution;
    
    // Basic test cases
    cout << "Test 1: " << solution.monotoneIncreasingDigits(10) << " (expected: 9)" << endl;
    cout << "Test 2: " << solution.monotoneIncreasingDigits(1234) << " (expected: 1234)" << endl;
    cout << "Test 3: " << solution.monotoneIncreasingDigits(332) << " (expected: 299)" << endl;
    
    // Edge cases
    cout << "Test 4: " << solution.monotoneIncreasingDigits(1) << " (expected: 1)" << endl;
    cout << "Test 5: " << solution.monotoneIncreasingDigits(9) << " (expected: 9)" << endl;
    cout << "Test 6: " << solution.monotoneIncreasingDigits(100) << " (expected: 99)" << endl;
    
    // More complex cases
    cout << "Test 7: " << solution.monotoneIncreasingDigits(54321) << " (expected: 49999)" << endl;
    cout << "Test 8: " << solution.monotoneIncreasingDigits(1000) << " (expected: 999)" << endl;
    cout << "Test 9: " << solution.monotoneIncreasingDigits(1111) << " (expected: 1111)" << endl;
    cout << "Test 10: " << solution.monotoneIncreasingDigits(2333332) << " (expected: 1999999)" << endl;
    
    return 0;
}
