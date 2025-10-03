#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    // // 暴力超时
    // vector<int> dailyTemperatures(vector<int> &temperatures) {
    //     if(temperatures.size() < 2) return {0};
    //     vector<int> result(temperatures.size(), 0);
        
    //     for(int i = 0; i < temperatures.size(); i ++) {
    //         for(int j = 1; j < temperatures.size() - i; j ++) {
    //             if(temperatures[i + j] > temperatures[i]) {
    //                 result[i] = j;
    //                 break;
    //             }
    //         }
    //     }
    //     return result;
    // }

    vector<int> dailyTemperatures(vector<int> &temperatures) {
        stack<int> st;
        vector<int> result(temperatures.size(), 0);

        st.push(0);
        for(int i = 1; i < temperatures.size(); i ++) {
            while(!st.empty() && temperatures[i] > temperatures[st.top()]) {
                result[st.top()] = i - st.top();
                st.pop(); 
            }
            st.push(i);            
        }
        return result;
    }
};

int main() {
    Solution sol;

    // Test 1: Example case
    vector<int> temps1 = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> res1 = sol.dailyTemperatures(temps1);
    for (int r : res1) cout << r << " ";
    cout << endl; // Expected: 1 1 4 2 1 1 0 0

    // Test 2: All same temperatures
    vector<int> temps2 = {70, 70, 70, 70};
    vector<int> res2 = sol.dailyTemperatures(temps2);
    for (int r : res2) cout << r << " ";
    cout << endl; // Expected: 0 0 0 0

    // Test 3: Strictly decreasing
    vector<int> temps3 = {80, 79, 78, 77};
    vector<int> res3 = sol.dailyTemperatures(temps3);
    for (int r : res3) cout << r << " ";
    cout << endl; // Expected: 0 0 0 0

    // Test 4: Strictly increasing
    vector<int> temps4 = {60, 61, 62, 63};
    vector<int> res4 = sol.dailyTemperatures(temps4);
    for (int r : res4) cout << r << " ";
    cout << endl; // Expected: 1 1 1 0

    // Test 5: Single element
    vector<int> temps5 = {90};
    vector<int> res5 = sol.dailyTemperatures(temps5);
    for (int r : res5) cout << r << " ";
    cout << endl; // Expected: 0

    // Test 6: Two elements, increasing
    vector<int> temps6 = {65, 70};
    vector<int> res6 = sol.dailyTemperatures(temps6);
    for (int r : res6) cout << r << " ";
    cout << endl; // Expected: 1 0

    // Test 7: Two elements, decreasing
    vector<int> temps7 = {70, 65};
    vector<int> res7 = sol.dailyTemperatures(temps7);
    for (int r : res7) cout << r << " ";
    cout << endl; // Expected: 0 0

    return 0;
}

