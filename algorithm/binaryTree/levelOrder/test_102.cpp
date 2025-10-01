#include <iostream>
#include <vector>
#include <queue>

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
public:
    // 算法思路：
    //          1. 队列内，每弹出一个节点，则将其左右子树节点进队
    vector<vector<int>> levelOrder(TreeNode *root) {
        if(root == nullptr) return {};
        vector<vector<int>> result;
        queue<TreeNode*> que;

        que.push(root);
        while(!que.empty()) {
            size_t sizeQue = que.size();
            vector<int> level;

            for(size_t i = 0; i < sizeQue; i ++) {
                TreeNode *curNode = que.front();
                que.pop();

                level.push_back(curNode->val);
                if(curNode->left != nullptr) que.push(curNode->left);
                if(curNode->right != nullptr) que.push(curNode->right);
            }
            result.push_back(level);
        }
        return result;
    }
};

int main()
{
    // 构建测试用例1：空树
    Solution sol;
    TreeNode* root1 = nullptr;
    auto res1 = sol.levelOrder(root1);
    cout << "Test 1 (空树): ";
    cout << "[";
    for (const auto& level : res1) {
        cout << "[";
        for (int v : level) cout << v << " ";
        cout << "]";
    }
    cout << "]" << endl;

    // 构建测试用例2：单节点树
    TreeNode* root2 = new TreeNode(1);
    auto res2 = sol.levelOrder(root2);
    cout << "Test 2 (单节点): ";
    cout << "[";
    for (const auto& level : res2) {
        cout << "[";
        for (int v : level) cout << v << " ";
        cout << "]";
    }
    cout << "]" << endl;

    // 构建测试用例3：多层树
    //      3
    //     / \
    //    9  20
    //       /  \
    //      15   7
    TreeNode* root3 = new TreeNode(3);
    root3->left = new TreeNode(9);
    root3->right = new TreeNode(20, new TreeNode(15), new TreeNode(7));
    auto res3 = sol.levelOrder(root3);
    cout << "Test 3 (多层树): ";
    cout << "[";
    for (const auto& level : res3) {
        cout << "[";
        for (int v : level) cout << v << " ";
        cout << "]";
    }
    cout << "]" << endl;

    // 构建测试用例4：左斜树
    //    1
    //   /
    //  2
    // /
    //3
    TreeNode* root4 = new TreeNode(1, new TreeNode(2, new TreeNode(3), nullptr), nullptr);
    auto res4 = sol.levelOrder(root4);
    cout << "Test 4 (左斜树): ";
    cout << "[";
    for (const auto& level : res4) {
        cout << "[";
        for (int v : level) cout << v << " ";
        cout << "]";
    }
    cout << "]" << endl;

    // 构建测试用例5：右斜树
    // 1
    //  \
    //   2
    //    \
    //     3
    TreeNode* root5 = new TreeNode(1, nullptr, new TreeNode(2, nullptr, new TreeNode(3)));
    auto res5 = sol.levelOrder(root5);
    cout << "Test 5 (右斜树): ";
    cout << "[";
    for (const auto& level : res5) {
        cout << "[";
        for (int v : level) cout << v << " ";
        cout << "]";
    }
    cout << "]" << endl;
}