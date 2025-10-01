#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
    TreeNode(int val, TreeNode *left, TreeNode *right) : val(val), left(nullptr), right(nullptr) {}
};

class Solution {
private:
    void traversal(TreeNode *curNode) {
        if(curNode == nullptr) return ;

        swap(curNode->left, curNode->right);    // 前序实现
        traversal(curNode->left);
        // 无法中序实现，在中间进行处理的话
        // curNode->right = curNode->left
        // 导致 curNode->left 重复处理，curNode->right 未被处理
        traversal(curNode->right);
        //  swap(curNode->left, curNode->right);    // 后序实现
    }

public:
    // // 1. 层序实现
    // TreeNode *invertTree(TreeNode *root) {
    //     if(root == nullptr) return nullptr;
    //     queue<TreeNode*> que;

    //     que.push(root);
    //     while(!que.empty()) {
    //         TreeNode *curNode = que.front();
    //         que.pop();

    //         TreeNode *temp = curNode->right;
    //         curNode->right = curNode->left;
    //         curNode->left = temp;
    //         if(curNode->left != nullptr) que.push(curNode->left);
    //         if(curNode->right != nullptr) que.push(curNode->right);
    //     }
    //     return root;
    // }

    // 2. 前/后序实现
    TreeNode *invertTree(TreeNode *root) {
        if(root == nullptr) return root;
        TreeNode *curNode = root;

        traversal(curNode);

        return root;
    }
};

int main()
{
    Solution sol;

    // 构造二叉树: 
    //      1
    //     / \
    //    2   3
    //   / \
    //  4   5
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "原始树层序遍历: ";
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* node = q.front(); q.pop();
        cout << node->val << " ";
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }
    cout << endl;

    // 反转二叉树
    TreeNode* inverted = sol.invertTree(root);

    cout << "反转后树层序遍历: ";
    q.push(inverted);
    while (!q.empty()) {
        TreeNode* node = q.front(); q.pop();
        cout << node->val << " ";
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }
    cout << endl;

    // 正确结果提示
    cout << "预期反转后层序遍历结果: 1 3 2 5 4" << endl;

}
