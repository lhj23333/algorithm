#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    static bool cmp(vector<int> &a, vector<int> &b) {
        return a[0] < b[0];
    }

    vector<vector<int>> process(vector<vector<int>> &intervals) {
        vector<vector<int>> que;
        sort(intervals.begin(), intervals.end(), cmp);
        
        que.push_back(intervals[0]);
        for(size_t i = 1; i < intervals.size(); i++) {
            if(que.back()[1] < intervals[i][0]) que.push_back(intervals[i]);
            else {
                if(que.back()[1] <= intervals[i][1]) que.back()[1] = intervals[i][1];
            } 
        }
        return que;
    }

public:    
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        if(intervals.size() == 0) return {};
        return process(intervals);
    }
};

void printIntervals(const vector<vector<int>>& intervals) {
    for (const auto& interval : intervals) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;
}

int main() {
    Solution sol;

    // Test 1: Overlapping intervals
    vector<vector<int>> intervals1 = {{1,3},{2,6},{8,10},{15,18}};
    auto res1 = sol.merge(intervals1);
    cout << "Test 1: ";
    printIntervals(res1); // Expected: [1, 6] [8, 10] [15, 18]

    // Test 2: No overlapping intervals
    vector<vector<int>> intervals2 = {{1,2},{3,4},{5,6}};
    auto res2 = sol.merge(intervals2);
    cout << "Test 2: ";
    printIntervals(res2); // Expected: [1, 2] [3, 4] [5, 6]

    // Test 3: All intervals overlap into one
    vector<vector<int>> intervals3 = {{1,5},{2,6},{3,7}};
    auto res3 = sol.merge(intervals3);
    cout << "Test 3: ";
    printIntervals(res3); // Expected: [1, 7]

    // Test 4: Single interval
    vector<vector<int>> intervals4 = {{1,10}};
    auto res4 = sol.merge(intervals4);
    cout << "Test 4: ";
    printIntervals(res4); // Expected: [1, 10]

    // Test 5: Empty input
    vector<vector<int>> intervals5 = {};
    auto res5 = sol.merge(intervals5);
    cout << "Test 5: ";
    printIntervals(res5); // Expected: (empty)

    // Test 6: Intervals with same start
    vector<vector<int>> intervals6 = {{1,4},{1,5},{1,3}};
    auto res6 = sol.merge(intervals6);
    cout << "Test 6: ";
    printIntervals(res6); // Expected: [1, 5]

    // Test 7: Intervals with same end
    vector<vector<int>> intervals7 = {{1,4},{2,4},{3,4}};
    auto res7 = sol.merge(intervals7);
    cout << "Test 7: ";
    printIntervals(res7); // Expected: [1, 4]

    // Test 8: Nested intervals
    vector<vector<int>> intervals8 = {{1,10},{2,3},{4,5},{6,7}};
    auto res8 = sol.merge(intervals8);
    cout << "Test 8: ";
    printIntervals(res8); // Expected: [1, 10]

    // Test 9: Touching intervals
    vector<vector<int>> intervals9 = {{1,2},{2,3},{3,4}};
    auto res9 = sol.merge(intervals9);
    cout << "Test 9: ";
    printIntervals(res9); // Expected: [1, 4]

    return 0;
}
