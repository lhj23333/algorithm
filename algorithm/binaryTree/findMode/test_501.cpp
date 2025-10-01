#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <functional>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
    TreeNode(int val, TreeNode *left, TreeNode *right) : val(val), left(left), right(right) {}
};

class Solution {
private:
    // vector<int> mode;
    unordered_set<int> set;
    TreeNode *preNode = nullptr;
    int count = 0;
    int maxCount = INT_MIN;
    // unordered_map<int, int> map;

    // // 1. 暴力遍历实现
    // void traversal(TreeNode *curNode) {
    //     if(curNode == nullptr) return ;

    //     traversal(curNode->left);
    //     traversal(curNode->right);
    //     map[curNode->val] ++;
    // }

    // 2. 双指针单词遍历实现
    void traversal(TreeNode *curNode) {
        if(curNode == nullptr) return ;

        traversal(curNode->left);
        if(preNode == nullptr || curNode->val != preNode->val) count = 1;
        else count ++;
        
        preNode = curNode;

        if(count == maxCount) {
            set.insert(curNode->val);
        } else if(count > maxCount) {
            maxCount = count;
            set.clear();
            set.insert(curNode->val);
        }
        traversal(curNode->right);
    }

public:
    // // 1. 前序遍历保存频率 -> 获取最大频率 -> 找出最大频率数值结果
    // vector<int> findMode(TreeNode *root) {
    //     if(root == nullptr) return {};
    //     traversal(root);

    //     int maxCnt = INT_MIN;
    //     for(auto &it : map) {
    //         maxCnt = max(it.second, maxCnt);
    //     }

    //     for(auto &it: map) {
    //         if(it.second == maxCnt) {
    //             mode.push_back(it.first);
    //         }
    //     }
    //     return mode; 
    // }

    vector<int> findMode(TreeNode *root) {
        if(root == nullptr) return {};
        traversal(root);
        vector<int> result;

        for(auto &it : set) {
            result.push_back(it);
        }

        return result;
    }
};

static vector<int> computeExpectedMode(TreeNode *root) {
    unordered_map<int,int> cnt;
    function<void(TreeNode*)> dfs = [&](TreeNode *n) {
        if(!n) return;
        cnt[n->val]++;
        dfs(n->left);
        dfs(n->right);
    };
    dfs(root);
    if(cnt.empty()) return {};
    int maxc = 0;
    for(auto &p: cnt) maxc = max(maxc, p.second);
    vector<int> res;
    for(auto &p: cnt) if(p.second == maxc) res.push_back(p.first);
    sort(res.begin(), res.end());
    return res;
}

static void printVec(const vector<int> &v) {
    cout << "[";
    for(size_t i=0;i<v.size();++i) {
        if(i) cout << ", ";
        cout << v[i];
    }
    cout << "]";
}

int main()
{
    // Test 1: empty tree
    {
        TreeNode *root = nullptr;
        Solution sol;
        auto res = sol.findMode(root);
        auto expect = computeExpectedMode(root);
        sort(res.begin(), res.end());
        cout << "Test 1 (empty): result ";
        printVec(res);
        cout << "  expected ";
        printVec(expect);
        cout << "\n";
    }

    // Test 2: single node
    {
        TreeNode *root = new TreeNode(1);
        Solution sol;
        auto res = sol.findMode(root);
        auto expect = computeExpectedMode(root);
        sort(res.begin(), res.end());
        cout << "Test 2 (single): result ";
        printVec(res);
        cout << "  expected ";
        printVec(expect);
        cout << "\n";
    }

    // Test 3: [1, null, 2, 2] -> mode is 2
    {
        TreeNode *root = new TreeNode(1);
        root->right = new TreeNode(2);
        root->right->left = new TreeNode(2);
        Solution sol;
        auto res = sol.findMode(root);
        auto expect = computeExpectedMode(root);
        sort(res.begin(), res.end());
        cout << "Test 3 ([1,null,2,2]): result ";
        printVec(res);
        cout << "  expected ";
        printVec(expect);
        cout << "\n";
    }

    // Test 4: multiple modes (1 and 2 both appear twice)
    {
        TreeNode *root = new TreeNode(2);
        root->left = new TreeNode(1);
        root->left->left = new TreeNode(1);
        root->right = new TreeNode(2);
        root->right->right = new TreeNode(3);
        Solution sol;
        auto res = sol.findMode(root);
        auto expect = computeExpectedMode(root);
        sort(res.begin(), res.end());
        cout << "Test 4 (modes 1 and 2): result ";
        printVec(res);
        cout << "  expected ";
        printVec(expect);
        cout << "\n";
    }

    // Test 5: larger counts, mode 4
    {
        TreeNode *root = new TreeNode(4);
        root->left = new TreeNode(2);
        root->right = new TreeNode(4);
        root->left->left = new TreeNode(4);
        root->left->right = new TreeNode(3);
        root->right->right = new TreeNode(5);
        Solution sol;
        auto res = sol.findMode(root);
        auto expect = computeExpectedMode(root);
        sort(res.begin(), res.end());
        cout << "Test 5 (mode 4): result ";
        printVec(res);
        cout << "  expected ";
        printVec(expect);
        cout << "\n";
    }

    return 0;
}
