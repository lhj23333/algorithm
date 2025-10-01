#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.empty()) return 0;
        
        int result = INT_MIN;
        int sum = 0;
        for(size_t i = 0; i < nums.size(); i ++) {
            sum += nums[i];
            result = max(result, sum);
            if(sum < 0) sum = 0;
        }

        return result;
    }
};

static void printVec(const vector<int>& v) {
    cout << "{";
    for(size_t i = 0; i < v.size(); ++i) {
        if(i) cout << ", ";
        cout << v[i];
    }
    cout << "}";
}

int main()
{
    Solution sol;

    vector<vector<int>> tests = {
        {-2,1,-3,4,-1,2,1,-5,4}, // expected 6
        {1},                     // expected 1
        {5,4,-1,7,8},            // expected 23
        {-1},                    // expected -1
        {-2,-3,-1,-5},           // expected -1
        {0,0,0},                 // expected 0
        {}                       // expected 0 (as handled by this implementation)
    };

    vector<int> expected = {6, 1, 23, -1, -1, 0, 0};

    for(size_t i = 0; i < tests.size(); ++i) {
        vector<int> t = tests[i];
        int got = sol.maxSubArray(t);
        cout << "Test " << (i+1) << ": input = ";
        printVec(t);
        cout << " | Got = " << got << " | 正确结果提示: expected = " << expected[i];
        if(got == expected[i]) cout << " | PASS";
        else cout << " | FAIL";
        cout << endl;
    }

    return 0;
}