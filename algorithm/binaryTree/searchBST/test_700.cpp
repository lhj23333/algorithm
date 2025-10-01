#include <iostream>

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
    // 二叉搜索树：对于任意一个节点：
    //      - 左子树所有节点的值 < 当前节点值
    //      - 右子树所有节点的值 > 当前节点值 
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == nullptr || root->val == val) return root;
        if (val < root->val) return searchBST(root->left, val);
        return searchBST(root->right, val);
    }
};

int main() {
    Solution sol;

    // Test Case 1: Simple BST with target present
    TreeNode* root1 = new TreeNode(4);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(7);
    root1->left->left = new TreeNode(1);
    root1->left->right = new TreeNode(3);
    TreeNode* result1 = sol.searchBST(root1, 2);
    cout << "Test 1 - Found value: " << (result1 ? result1->val : -1) << ", Expected: 2" << endl;

    // Test Case 2: Target not present
    TreeNode* result2 = sol.searchBST(root1, 5);
    cout << "Test 2 - Found value: " << (result2 ? result2->val : -1) << ", Expected: -1" << endl;

    // Test Case 3: Empty tree
    TreeNode* root3 = nullptr;
    TreeNode* result3 = sol.searchBST(root3, 1);
    cout << "Test 3 - Found value: " << (result3 ? result3->val : -1) << ", Expected: -1" << endl;

    // Test Case 4: Single node tree, target present
    TreeNode* root4 = new TreeNode(1);
    TreeNode* result4 = sol.searchBST(root4, 1);
    cout << "Test 4 - Found value: " << (result4 ? result4->val : -1) << ", Expected: 1" << endl;

    // Test Case 5: Single node tree, target not present
    TreeNode* result5 = sol.searchBST(root4, 2);
    cout << "Test 5 - Found value: " << (result5 ? result5->val : -1) << ", Expected: -1" << endl;

    // Test Case 6: Larger BST, target in right subtree
    TreeNode* root6 = new TreeNode(8);
    root6->left = new TreeNode(3);
    root6->right = new TreeNode(10);
    root6->left->left = new TreeNode(1);
    root6->left->right = new TreeNode(6);
    root6->right->right = new TreeNode(14);
    root6->left->right->left = new TreeNode(4);
    root6->left->right->right = new TreeNode(7);
    TreeNode* result6 = sol.searchBST(root6, 6);
    cout << "Test 6 - Found value: " << (result6 ? result6->val : -1) << ", Expected: 6" << endl;

    // Test Case 7: Target is root
    TreeNode* result7 = sol.searchBST(root6, 8);
    cout << "Test 7 - Found value: " << (result7 ? result7->val : -1) << ", Expected: 8" << endl;

    // Clean up memory (optional, for good practice)
    // Note: In a real test, you might want to implement a delete function for the tree

    return 0;
}
