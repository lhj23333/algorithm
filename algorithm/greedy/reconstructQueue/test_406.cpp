#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    static bool cmp(const vector<int> &a, const vector<int> &b) {
        if(a[0] == b[0]) return a[1] < b[1];
        return a[0] > b[0];
    }

public:
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people) {
        vector<vector<int>> que;
        
        // 1. 进行升高维度排序（前高人数为次要）
        sort(people.begin(), people.end(), cmp);
        for(int i = 0; i < people.size(); i ++) {
            int position = people[i][1];
            // 2. 依据前高人数进行排序调整
            //    由于已依据身高由高向低排序，进行由前向后遍历时，低身高的前高属性即为排序插入位置
            que.insert(que.begin() + position, people[i]);
        }
        return que;
    }
};

int main() {
    Solution solution;
    
    // Test case 1
    vector<vector<int>> people1 = {{7,0},{4,4},{7,1},{5,0},{6,1},{5,2}};
    cout << "Test case 1:" << endl;
    cout << "Input: [[7,0],[4,4],[7,1],[5,0],[6,1],[5,2]]" << endl;
    vector<vector<int>> result1 = solution.reconstructQueue(people1);
    cout << "Output: [";
    for(int i = 0; i < result1.size(); i++) {
        cout << "[" << result1[i][0] << "," << result1[i][1] << "]";
        if(i < result1.size() - 1) cout << ",";
    }
    cout << "]" << endl;
    cout << "Expected: [[5,0],[7,0],[5,2],[6,1],[4,4],[7,1]]" << endl << endl;
    
    // Test case 2
    vector<vector<int>> people2 = {{6,0},{5,0},{4,0},{3,2},{2,2},{1,4}};
    cout << "Test case 2:" << endl;
    cout << "Input: [[6,0],[5,0],[4,0],[3,2],[2,2],[1,4]]" << endl;
    vector<vector<int>> result2 = solution.reconstructQueue(people2);
    cout << "Output: [";
    for(int i = 0; i < result2.size(); i++) {
        cout << "[" << result2[i][0] << "," << result2[i][1] << "]";
        if(i < result2.size() - 1) cout << ",";
    }
    cout << "]" << endl;
    cout << "Expected: [[4,0],[5,0],[2,2],[3,2],[1,4],[6,0]]" << endl;
    
    return 0;
}