#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
// 代码思路：创建单向队列来存放滑动窗口可能最大值（这个队列大小与k无关系）
//          1. 当滑动窗口弹出元素时（这个比较懊恼，但可以根据情况进行分析）
//             - 当该数为最大值时，那么会被保留在队列出口（front）
//             - 当该数不为最大值时，丢其内也没有影响，后续可能成为最大值，也可能被弹出（push 操作实现），
//          2. 当滑动窗口推入元素时，从队列末尾开始进行判断，弹出比其小的所有元素
//          3. 获取最大值（单向队列 -> 最大值（front））
//          综上，该单向队列仅需实现
//          1. 弹出时，判断要弹出数是否是最大值，是->弹出，不是->不做处理
//          2. 推入时，进行重排序操作
private:
    class MyWindow {
    public:
        deque<int> dq;

        void pop(int value) {
            if(!dq.empty() && value == dq.front()) {
                dq.pop_front();
            }
        }

        void push(int value) {
            while(!dq.empty() && value > dq.back()){
                dq.pop_back();
            }
            dq.push_back(value);
        }

        int getMax() {
            return dq.front(); 
        }
    };

public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        if(nums.empty() || k <= 0) return {};
        vector<int> result;
        MyWindow wd;
        size_t i = 0;

        // 初始化窗口，只进不出
        for(; i < k; i++) wd.push(nums[i]);
        result.push_back(wd.getMax());

        // 窗口滑动
        for(; i < nums.size() ; i ++) {
            wd.pop(nums[i - k]);
            wd.push(nums[i]);
            result.push_back(wd.getMax());
        }

        return result;
    }
};

int main() {
    Solution sol;

    // Test case 1: Basic test
    vector<int> nums1 = {1, 3, -1, -3, 5, 3, 6, 7};
    int k1 = 3;
    vector<int> res1 = sol.maxSlidingWindow(nums1, k1);
    cout << "Test 1: ";
    for (int n : res1) cout << n << " ";
    cout << endl;

    // Test case 2: Window size is 1
    vector<int> nums2 = {4, 2, 12, 3};
    int k2 = 1;
    vector<int> res2 = sol.maxSlidingWindow(nums2, k2);
    cout << "Test 2: ";
    for (int n : res2) cout << n << " ";
    cout << endl;

    // Test case 3: Window size equals array size
    vector<int> nums3 = {9, 5, 3, 1, 6};
    int k3 = 5;
    vector<int> res3 = sol.maxSlidingWindow(nums3, k3);
    cout << "Test 3: ";
    for (int n : res3) cout << n << " ";
    cout << endl;

    // Test case 4: Empty array
    vector<int> nums4 = {};
    int k4 = 3;
    vector<int> res4 = sol.maxSlidingWindow(nums4, k4);
    cout << "Test 4: ";
    for (int n : res4) cout << n << " ";
    cout << endl;

    // Test case 5: k is zero
    vector<int> nums5 = {1, 2, 3};
    int k5 = 0;
    vector<int> res5 = sol.maxSlidingWindow(nums5, k5);
    cout << "Test 5: ";
    for (int n : res5) cout << n << " ";
    cout << endl;

    // Test case 6: All elements are the same
    vector<int> nums6 = {2, 2, 2, 2, 2};
    int k6 = 2;
    vector<int> res6 = sol.maxSlidingWindow(nums6, k6);
    cout << "Test 6: ";
    for (int n : res6) cout << n << " ";
    cout << endl;

    // Test case 7: Decreasing sequence
    vector<int> nums7 = {5, 4, 3, 2, 1};
    int k7 = 3;
    vector<int> res7 = sol.maxSlidingWindow(nums7, k7);
    cout << "Test 7: ";
    for (int n : res7) cout << n << " ";
    cout << endl;

    // Test case 8: Increasing sequence
    vector<int> nums8 = {1, 2, 3, 4, 5};
    int k8 = 2;
    vector<int> res8 = sol.maxSlidingWindow(nums8, k8);
    cout << "Test 8: ";
    for (int n : res8) cout << n << " ";
    cout << endl;

    return 0;
}