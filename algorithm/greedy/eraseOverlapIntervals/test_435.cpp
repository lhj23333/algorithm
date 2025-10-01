#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    static bool cmp(vector<int> &a, vector<int> &b){
        return a[0] < b[0];
    }

    int process(vector<vector<int>> &intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        
        int cnt = 0;
        for(size_t i = 1; i < intervals.size(); i++) {
            if(intervals[i][0] < intervals[i - 1][1]) {
                cnt ++;
                intervals[i][1] = min(intervals[i - 1][1], intervals[i][1]);
            }
        }
        return cnt;
    }

public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size() == 0) return 0;
        return process(intervals);
    }
};

int main() {
    Solution solution;
    
    // Test case 1: Basic overlapping intervals
    vector<vector<int>> test1 = {{1,2},{2,3},{3,4},{1,3}};
    int result1 = solution.eraseOverlapIntervals(test1);
    cout << "Test 1: " << result1 << " (Expected: 1)" << endl;
    
    // Test case 2: No overlapping intervals
    vector<vector<int>> test2 = {{1,2},{2,3},{3,4}};
    int result2 = solution.eraseOverlapIntervals(test2);
    cout << "Test 2: " << result2 << " (Expected: 0)" << endl;
    
    // Test case 3: All intervals overlap
    vector<vector<int>> test3 = {{1,2},{1,2},{1,2}};
    int result3 = solution.eraseOverlapIntervals(test3);
    cout << "Test 3: " << result3 << " (Expected: 2)" << endl;
    
    // Test case 4: Empty input
    vector<vector<int>> test4 = {};
    int result4 = solution.eraseOverlapIntervals(test4);
    cout << "Test 4: " << result4 << " (Expected: 0)" << endl;
    
    // Test case 5: Single interval
    vector<vector<int>> test5 = {{1,2}};
    int result5 = solution.eraseOverlapIntervals(test5);
    cout << "Test 5: " << result5 << " (Expected: 0)" << endl;
    
    // Test case 6: Complex overlapping case
    vector<vector<int>> test6 = {{1,4},{2,3},{3,4},{1,2}};
    int result6 = solution.eraseOverlapIntervals(test6);
    cout << "Test 6: " << result6 << " (Expected: 1)" << endl;
    
    return 0;
}
