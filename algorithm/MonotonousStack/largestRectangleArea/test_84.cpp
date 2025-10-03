#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    // 算法思路：维护单调递增栈，当出现小于栈顶元素时，计算最大lagest值
    int largestRectangleArea(vector<int> &heights) {
        int largestArea = 0;
        stack<int> st;
        heights.insert(heights.begin(), 0);
        heights.push_back(0);

        st.push(0);
        for(int i = 1; i < heights.size(); i ++) {
            if(heights[i] == heights[st.top()]) st.pop();
            else {
                while(!st.empty() && heights[i] < heights[st.top()]) {
                    int mid = st.top();
                    st.pop();
                    if(!st.empty()) {
                        int w = i - st.top() - 1;
                        int h = heights[mid];
                        largestArea = max(largestArea, w*h);
                    }
                }
            }
            st.push(i);
        }
        return largestArea;
    }
};

void test(vector<int> heights, int expected) {
    Solution sol;
    int result = sol.largestRectangleArea(heights);
    cout << "Input: ";
    for (int h : heights) cout << h << " ";
    cout << "\nExpected: " << expected << ", Got: " << result << endl;
    cout << (result == expected ? "PASS" : "FAIL") << endl << endl;
}

int main() {
    test({2,1,5,6,2,3}, 10);         // Standard example
    test({2,4}, 4);                  // Two bars
    test({1,1,1,1}, 4);              // All same height
    test({6,2,5,4,5,1,6}, 12);       // Leetcode example
    test({0,0,0,0}, 0);              // All zeros
    test({1}, 1);                    // Single bar
    test({2,1,2}, 3);                // Valley in the middle
    test({3,6,5,7,4,8,1,0}, 20);     // Mixed heights
    test({5,4,1,2}, 6);              // Decreasing then increasing
    test({10000}, 10000);            // Large single bar
    test({200,200,200,200,200,201,201}, 1400);
    return 0;
}
