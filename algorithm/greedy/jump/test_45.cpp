#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int result;

    // 递归法：时间超时
    void backtracking(vector<int> &nums, size_t startIndex, int cnt) {
        if(startIndex >= nums.size() - 1) {
            result = min(result, cnt);
            return ;
        }
        if(startIndex > nums.size() - 1 || nums[startIndex] == 0) return;

        for(size_t i = 1; i <= nums[startIndex]; i ++) {
            startIndex += i;
            backtracking(nums, startIndex, cnt + 1);
            startIndex -= i;
        }
    }

public:
    // int jump(vector<int> &nums) { 
    //     result = INT_MAX;
    //     backtracking(nums, 0, 0);
    //     return result;
    // }

    int jump(vector<int> &nums) {
        if(nums.size() == 1) return 0;

        size_t curDistance = 0;
        size_t nextDistance = 0;
        int result = 0;

        for(size_t i = 0; i < nums.size(); i ++) {
            nextDistance = max(i + nums[i], nextDistance);

            if(i == curDistance) {
                curDistance = nextDistance;
                result ++;
                if(curDistance >= nums.size() - 1) break;
            }
        }

        return result;
    }
};

static void printVec(const vector<int>& v) {
    cout << "{";
    for(size_t i=0;i<v.size();++i){
        if(i) cout << ",";
        cout << v[i];
    }
    cout << "}";
}

int main()
{
    Solution sol;
    vector<vector<int>> cases = {
        {2,3,1,1,4},    // expected 2
        {2,3,0,1,4},    // expected 2
        {0},            // expected 0
        {1,2},          // expected 1
        {1,1,1,1,1},    // expected 4
        {10,0,0,0},    // expected 1
        {5,6,4,4,6,9,4,4,7,4,4,8,2,6,8,1,5,9,6,5,2,7,9,7,9,6,9,4,1,6,8,8,4,4,2,0,3,8,5}
    };
    vector<int> expected = {2,2,0,1,4,1,5};

    for(size_t i=0;i<cases.size();++i){
        auto v = cases[i];
        int out = sol.jump(v);
        cout << "Test " << i+1 << " Input: ";
        printVec(v);
        cout << " -> Result: " << out << " | Expected (correct): " << expected[i];
        if(out == expected[i]) cout << " [PASS]";
        else cout << " [FAIL]";
        cout << "\n";
    }

    return 0;
}