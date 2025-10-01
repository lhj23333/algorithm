#include <iostream>
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
    // //  1. 层序实现
    // int maxDepth(TreeNode *root) {
    //     if(root == nullptr) return 0;
    //     queue<TreeNode*> que;
    //     int level = 0;

    //     que.push(root);
    //     while(!que.empty()) {
    //         size_t sizeQue = que.size();
    //         for(size_t i = 0; i < sizeQue; i++) {
    //             TreeNode *curNode = que.front();
    //             que.pop();

    //             if(curNode->left != nullptr) que.push(curNode->left);
    //             if(curNode->right != nullptr) que.push(curNode->right);
    //         }
    //         level ++;
    //     }
    //     return level;
    // }

    // 2. 递归实现
    // 算法思路：后序遍历 -> 根节点高度
    int maxDepth(TreeNode *root) {
        if(root == nullptr) return 0;

        int leftHigh = maxDepth(root->left);
        int rightHigh = maxDepth(root->right);
        int curHigh = 1 + max(leftHigh, rightHigh);

        return curHigh;
    }
};

int main()
{
    // Test 1: Empty tree
    Solution sol;
    TreeNode* root1 = nullptr;
    cout << "Test 1 (Empty tree): " << sol.maxDepth(root1) << endl; // Expected: 0

    // Test 2: Single node
    TreeNode* root2 = new TreeNode(1);
    cout << "Test 2 (Single node): " << sol.maxDepth(root2) << endl; // Expected: 1

    // Test 3: Two levels
    TreeNode* root3 = new TreeNode(1);
    root3->left = new TreeNode(2);
    root3->right = new TreeNode(3);
    cout << "Test 3 (Two levels): " << sol.maxDepth(root3) << endl; // Expected: 2

    // Test 4: Left skewed tree
    TreeNode* root4 = new TreeNode(1);
    root4->left = new TreeNode(2);
    root4->left->left = new TreeNode(3);
    cout << "Test 4 (Left skewed): " << sol.maxDepth(root4) << endl; // Expected: 3

    // Test 5: Right skewed tree
    TreeNode* root5 = new TreeNode(1);
    root5->right = new TreeNode(2);
    root5->right->right = new TreeNode(3);
    cout << "Test 5 (Right skewed): " << sol.maxDepth(root5) << endl; // Expected: 3

    // Test 6: Balanced tree
    TreeNode* root6 = new TreeNode(1);
    root6->left = new TreeNode(2);
    root6->right = new TreeNode(3);
    root6->left->left = new TreeNode(4);
    root6->left->right = new TreeNode(5);
    root6->right->left = new TreeNode(6);
    root6->right->right = new TreeNode(7);
    cout << "Test 6 (Balanced tree): " << sol.maxDepth(root6) << endl; // Expected: 3
}