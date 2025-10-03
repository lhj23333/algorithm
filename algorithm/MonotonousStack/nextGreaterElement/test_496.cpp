#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
        vector<int> result(nums1.size(), -1);
        unordered_map<int, int> nextGreater;
        stack<int> st;

        st.push(nums2[0]);
        for(int i = 1; i < nums2.size(); i ++) {
            while(!st.empty() && nums2[i] > st.top()) {
                nextGreater[st.top()] = nums2[i];
                st.pop();
            }
            st.push(nums2[i]);
        }

        for(int i = 0; i < nums1.size(); i ++) {
            if(nextGreater.count(nums1[i])) result[i] = nextGreater[nums1[i]];
        }
        return result;
    }
};

int main() {
    Solution solution;
    
    // Test 1: Basic case from LeetCode problem 496
    vector<int> nums1_1 = {4, 1, 2};
    vector<int> nums2_1 = {1, 3, 4, 2};
    vector<int> result1 = solution.nextGreaterElement(nums1_1, nums2_1);
    cout << "Test 1: ";
    for(int num : result1) cout << num << " ";
    cout << endl; // Expected: -1 3 -1
    
    // Test 2: Another basic case
    vector<int> nums1_2 = {2, 4};
    vector<int> nums2_2 = {1, 2, 3, 4};
    vector<int> result2 = solution.nextGreaterElement(nums1_2, nums2_2);
    cout << "Test 2: ";
    for(int num : result2) cout << num << " ";
    cout << endl; // Expected: 3 -1
    
    // Test 3: Single element
    vector<int> nums1_3 = {1};
    vector<int> nums2_3 = {1, 2};
    vector<int> result3 = solution.nextGreaterElement(nums1_3, nums2_3);
    cout << "Test 3: ";
    for(int num : result3) cout << num << " ";
    cout << endl; // Expected: 2
    
    // Test 4: No greater elements
    vector<int> nums1_4 = {3, 2, 1};
    vector<int> nums2_4 = {3, 2, 1};
    vector<int> result4 = solution.nextGreaterElement(nums1_4, nums2_4);
    cout << "Test 4: ";
    for(int num : result4) cout << num << " ";
    cout << endl; // Expected: -1 -1 -1
    
    // Test 5: All elements have next greater
    vector<int> nums1_5 = {1, 2, 3};
    vector<int> nums2_5 = {1, 2, 3, 4};
    vector<int> result5 = solution.nextGreaterElement(nums1_5, nums2_5);
    cout << "Test 5: ";
    for(int num : result5) cout << num << " ";
    cout << endl; // Expected: 2 3 4
    
    return 0;
}
