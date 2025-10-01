#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    static bool cmp(vector<int> &a, vector<int> &b) {
        return a[0] < b[0];
    }

    int process(vector<vector<int>> &points) {
        sort(points.begin(), points.end(), cmp);
        
        int cnt = 1;
        for(size_t i = 1; i < points.size(); i++) {
            if(points[i][0] <= points[i - 1][1]) points[i][1] = min(points[i][1], points[i - 1][1]);
            else cnt ++;
        }
        return cnt;
    }

public:
    int findMinArrowShots(vector<vector<int>> &points) {
        if(points.size() == 0) return 0;
        return process(points);
    }
};

int main() {
    Solution solution;
    
    // Test case 1
    vector<vector<int>> points1 = {{10,16}, {2,8}, {1,6}, {7,12}};
    int result1 = solution.findMinArrowShots(points1);
    cout << "Test 1 - Input: [[10,16],[2,8],[1,6],[7,12]]" << endl;
    cout << "Output: " << result1 << ", Expected: 2" << endl;
    cout << endl;
    
    // Test case 2
    vector<vector<int>> points2 = {{1,2}, {3,4}, {5,6}, {7,8}};
    int result2 = solution.findMinArrowShots(points2);
    cout << "Test 2 - Input: [[1,2],[3,4],[5,6],[7,8]]" << endl;
    cout << "Output: " << result2 << ", Expected: 4" << endl;
    cout << endl;
    
    // Test case 3
    vector<vector<int>> points3 = {{1,2}, {2,3}, {3,4}, {4,5}};
    int result3 = solution.findMinArrowShots(points3);
    cout << "Test 3 - Input: [[1,2],[2,3],[3,4],[4,5]]" << endl;
    cout << "Output: " << result3 << ", Expected: 2" << endl;
    cout << endl;
    
    return 0;
}