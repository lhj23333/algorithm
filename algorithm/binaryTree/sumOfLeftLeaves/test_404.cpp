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
private:
    int traversial(TreeNode *curNode) {
        if(curNode == nullptr) return 0;

        int cntLeft = traversial(curNode->left);
        if((curNode->left != nullptr) && (curNode->left->left == nullptr) && (curNode->left->right == nullptr)) {
           cntLeft = curNode->left->val;
        }
        int cntRight = traversial(curNode->right);

        return cntLeft + cntRight;
    }

public:
    // // 1. 迭代法实现
    // int sumOfLeftLeaves(TreeNode *root) {
    //     if(root == nullptr) return 0;
    //     queue<TreeNode*> que;
    //     int count = 0;

    //     que.push(root);
    //     while(!que.empty()) {
    //         TreeNode *curNode = que.front();
    //         que.pop();
            
    //         if(curNode->left) {
    //             que.push(curNode->left);
    //             if(!curNode->left->left  && !curNode->left->right) {
    //                 count += curNode->left->val;
    //             }
    //         }
    //         if(curNode->right) que.push(curNode->right);
    //     }
    //     return count;
    // }

    // 2. 递归法实现
    int sumOfLeftLeaves(TreeNode *root) {
        if(!root) return 0;

        return traversial(root);
    }
};

// Helper function to build a binary tree
TreeNode* buildTree() {
    // Example tree:
    //      3
    //     / \
    //    9  20
    //      /  \
    //     15   7
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    return root;
}

int main()
{
    // Test 1: Example tree
    Solution sol;
    TreeNode* root1 = buildTree();
    int result1 = sol.sumOfLeftLeaves(root1);
    cout << "Test 1 result: " << result1 << endl;
    cout << "Expected: 24 (9 + 15)" << endl;

    // Test 2: Only root node
    TreeNode* root2 = new TreeNode(1);
    int result2 = sol.sumOfLeftLeaves(root2);
    cout << "Test 2 result: " << result2 << endl;
    cout << "Expected: 0" << endl;

    // Test 3: Left leaf only
    TreeNode* root3 = new TreeNode(1);
    root3->left = new TreeNode(2);
    int result3 = sol.sumOfLeftLeaves(root3);
    cout << "Test 3 result: " << result3 << endl;
    cout << "Expected: 2" << endl;

    // Test 4: Right leaf only
    TreeNode* root4 = new TreeNode(1);
    root4->right = new TreeNode(3);
    int result4 = sol.sumOfLeftLeaves(root4);
    cout << "Test 4 result: " << result4 << endl;
    cout << "Expected: 0" << endl;

    // Test 5: Complex tree
    TreeNode* root5 = new TreeNode(1);
    root5->left = new TreeNode(2);
    root5->right = new TreeNode(3);
    root5->left->left = new TreeNode(4);
    root5->left->right = new TreeNode(5);
    root5->right->left = new TreeNode(6);
    root5->right->right = new TreeNode(7);
    int result5 = sol.sumOfLeftLeaves(root5);
    cout << "Test 5 result: " << result5 << endl;
    cout << "Expected: 10 (4 + 6)" << endl;
}