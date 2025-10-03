#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int trap(vector<int> &height) {
        stack<int> st;
        int sum = 0;
    
        st.push(0);
        for(int i = 1; i < height.size(); i ++) {
            if(height[i] == height[st.top()]) st.pop();
            else {
                while(!st.empty() && height[i] > height[st.top()]) {
                    int mid = st.top();
                    st.pop();
                    if(!st.empty()) {
                        int h = min(height[i], height[st.top()]) - height[mid];
                        int w = i - st.top() - 1;
                        sum += h*w;           
                    }
                }
            }
            st.push(i);
        }
        return sum;
    }
};

int main() {
    Solution solution;
    
    // Test 1: Basic example from LeetCode
    vector<int> height1 = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << "Test 1: " << solution.trap(height1) << " (Expected: 6)" << endl;
    
    // Test 2: Simple valley
    vector<int> height2 = {4,2,0,3,2,5};
    cout << "Test 2: " << solution.trap(height2) << " (Expected: 9)" << endl;
    
    // Test 3: No water trapped
    vector<int> height3 = {1,2,3,4,5};
    cout << "Test 3: " << solution.trap(height3) << " (Expected: 0)" << endl;
    
    // Test 4: Decreasing heights
    vector<int> height4 = {5,4,3,2,1};
    cout << "Test 4: " << solution.trap(height4) << " (Expected: 0)" << endl;
    
    // Test 5: Single valley
    vector<int> height5 = {3,0,2};
    cout << "Test 5: " << solution.trap(height5) << " (Expected: 2)" << endl;
    
    // Test 6: Empty array
    vector<int> height6 = {};
    cout << "Test 6: " << solution.trap(height6) << " (Expected: 0)" << endl;
    
    // Test 7: Single element
    vector<int> height7 = {5};
    cout << "Test 7: " << solution.trap(height7) << " (Expected: 0)" << endl;
    
    // Test 8: Two elements
    vector<int> height8 = {3,2};
    cout << "Test 8: " << solution.trap(height8) << " (Expected: 0)" << endl;
    
    // Test 9: Flat terrain
    vector<int> height9 = {2,2,2,2};
    cout << "Test 9: " << solution.trap(height9) << " (Expected: 0)" << endl;
    
    // Test 10: Multiple valleys
    vector<int> height10 = {4,2,3,1,4};
    cout << "Test 10: " << solution.trap(height10) << " (Expected: 6)" << endl;
    
    return 0;
}
