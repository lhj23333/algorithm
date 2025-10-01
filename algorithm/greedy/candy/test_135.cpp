#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
private:

    // 算法思路：主顺序 -> 从左往右遍历
    //          1. 仅考虑右边孩子与当前孩子的关系处理
    //          2. 在右边孩子关系确定的基础之上，做左孩子关系的处理调整
    int process(vector<int> &ratings) {
        vector<int> candyNums(ratings.size(), 1);

        for(int i = 1; i < (int)ratings.size(); i ++) {
            if(ratings[i - 1] < ratings[i]) candyNums[i] = candyNums[i - 1] + 1;
        }
        
        for(int i = (int)ratings.size() - 2; i >= 0; i --) {
            if(ratings[i] > ratings[i + 1]) candyNums[i] = max(candyNums[i + 1] + 1, candyNums[i]);
        }

        int candySum = 0;
        for(auto &it : candyNums) candySum += it;
        
        return candySum;
    }

public:
    int candy(vector<int> &ratings) {
        if(ratings.size() == 0) return 0;
        return process(ratings);
    }
};


// reference correct implementation (used to print the expected correct result)
int expectedCandy(const vector<int>& ratings) {
    int n = (int)ratings.size();
    if (n == 0) return 0;
    vector<int> cand(n, 1);
    for (int i = 1; i < n; ++i) if (ratings[i] > ratings[i-1]) cand[i] = cand[i-1] + 1;
    for (int i = n-2; i >= 0; --i) if (ratings[i] > ratings[i+1]) cand[i] = max(cand[i], cand[i+1] + 1);
    return accumulate(cand.begin(), cand.end(), 0);
}

void printVec(const vector<int>& v) {
    cout << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        if (i) cout << ", ";
        cout << v[i];
    }
    cout << "]";
}

int main() {
    Solution sol;
    vector<vector<int>> tests = {
        {},                 // empty
        {1},                // single
        {1,1},              // all equal
        {1,2},              // increasing
        {2,1},              // decreasing
        {1,0,2},            // valley
        {1,3,4,5,2},        // peak near end
        {1,2,2},            // plateau
        {5,4,3,2,1},        // strictly decreasing
        {1,2,3,4,5}         // strictly increasing
    };

    for (size_t i = 0; i < tests.size(); ++i) {
        const auto& tc = tests[i];
        int expect = expectedCandy(tc);
        // call the Solution under test
        vector<int> tc_copy = tc;
        int actual = sol.candy(tc_copy);
        cout << "Test " << i+1 << ": ratings = ";
        printVec(tc);
        cout << " | expected = " << expect << " | actual = " << actual
             << " | " << (expect == actual ? "PASS" : "FAIL") << "\n";
    }

    return 0;
}
