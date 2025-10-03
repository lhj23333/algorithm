#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int> &nums) {
        stack<int> st;
        vector<int> combined(nums.begin(), nums.end());
        combined.insert(combined.end(), nums.begin(), nums.end());
        vector<int> result(combined.size(), -1);

        st.push(0);
        for(int i = 1; i < combined.size(); i++) {
            while(!st.empty() && combined[i] > combined[st.top()]) {
                result[st.top()] = combined[i];
                st.pop();
            }
            st.push(i);
        }

        return vector<int>(result.begin(), result.begin() + nums.size());
    }
};

int main() {
    Solution solution;
    
    // Test 1: Basic circular case
    vector<int> nums1 = {1, 2, 1};
    vector<int> result1 = solution.nextGreaterElements(nums1);
    cout << "Test 1: [1,2,1] -> [";
    for(int i = 0; i < result1.size(); i++) {
        cout << result1[i] << (i < result1.size() - 1 ? "," : "");
    }
    cout << "]" << endl; // Expected: [2,-1,2]
    
    // Test 2: All same elements
    vector<int> nums2 = {5, 5, 5, 5};
    vector<int> result2 = solution.nextGreaterElements(nums2);
    cout << "Test 2: [5,5,5,5] -> [";
    for(int i = 0; i < result2.size(); i++) {
        cout << result2[i] << (i < result2.size() - 1 ? "," : "");
    }
    cout << "]" << endl; // Expected: [-1,-1,-1,-1]
    
    // Test 3: Descending order
    vector<int> nums3 = {5, 4, 3, 2, 1};
    vector<int> result3 = solution.nextGreaterElements(nums3);
    cout << "Test 3: [5,4,3,2,1] -> [";
    for(int i = 0; i < result3.size(); i++) {
        cout << result3[i] << (i < result3.size() - 1 ? "," : "");
    }
    cout << "]" << endl; // Expected: [-1,5,5,5,5]
    
    // Test 4: Ascending order
    vector<int> nums4 = {1, 2, 3, 4, 5};
    vector<int> result4 = solution.nextGreaterElements(nums4);
    cout << "Test 4: [1,2,3,4,5] -> [";
    for(int i = 0; i < result4.size(); i++) {
        cout << result4[i] << (i < result4.size() - 1 ? "," : "");
    }
    cout << "]" << endl; // Expected: [2,3,4,5,-1]
    
    // Test 5: Single element
    vector<int> nums5 = {1};
    vector<int> result5 = solution.nextGreaterElements(nums5);
    cout << "Test 5: [1] -> [" << result5[0] << "]" << endl; // Expected: [-1]
    
    // Test 6: Two elements
    vector<int> nums6 = {2, 3};
    vector<int> result6 = solution.nextGreaterElements(nums6);
    cout << "Test 6: [2,3] -> [";
    for(int i = 0; i < result6.size(); i++) {
        cout << result6[i] << (i < result6.size() - 1 ? "," : "");
    }
    cout << "]" << endl; // Expected: [3,-1]
    
    return 0;
}
