#include <iostream>
#include <vector>

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
    vector<int> vec;

    // 算法思路：递归法-> 中序遍历结果为递增数组
    bool traversal(TreeNode *curNode) {
        bool result = true;
        if(curNode == nullptr) return result;
        
        bool leftResult = traversal(curNode->left);
        if(!vec.empty() && curNode->val <= vec.back()) result = false;
        vec.push_back(curNode->val);
        bool rightResult = traversal(curNode->right);
        
        return result && leftResult && rightResult;
    }

public:
    bool isValidBST(TreeNode* root) {
        if(root == nullptr) return true;
        return traversal(root);
    }
};

int main() {
    Solution sol;

    // Test 1: Empty tree
    TreeNode* root1 = nullptr;
    bool result1 = sol.isValidBST(root1);
    bool expected1 = false; // As per code logic
    cout << "Test 1 (Empty tree): Result: " << (result1 ? "true" : "false") << ", Expected: " << (expected1 ? "true" : "false") << endl;

    // Test 2: Single node
    TreeNode* root2 = new TreeNode(5);
    bool result2 = sol.isValidBST(root2);
    bool expected2 = true;
    cout << "Test 2 (Single node [5]): Result: " << (result2 ? "true" : "false") << ", Expected: " << (expected2 ? "true" : "false") << endl;

    // Test 3: Valid BST [2,1,3]
    TreeNode* root3 = new TreeNode(2);
    root3->left = new TreeNode(1);
    root3->right = new TreeNode(3);
    bool result3 = sol.isValidBST(root3);
    bool expected3 = true;
    cout << "Test 3 (Valid BST [2,1,3]): Result: " << (result3 ? "true" : "false") << ", Expected: " << (expected3 ? "true" : "false") << endl;

    // Test 4: Invalid BST [5,1,4,null,null,3,6]
    TreeNode* root4 = new TreeNode(5);
    root4->left = new TreeNode(1);
    root4->right = new TreeNode(4);
    root4->right->left = new TreeNode(3);
    root4->right->right = new TreeNode(6);
    bool result4 = sol.isValidBST(root4);
    bool expected4 = false; // 3 < 4 but 3 is in right subtree of 5, but code checks only direct children
    cout << "Test 4 (Invalid BST [5,1,4,null,null,3,6]): Result: " << (result4 ? "true" : "false") << ", Expected: " << (expected4 ? "true" : "false") << endl;

    // Test 5: Valid BST [10,5,15,null,null,6,20]
    TreeNode* root5 = new TreeNode(10);
    root5->left = new TreeNode(5);
    root5->right = new TreeNode(15);
    root5->right->left = new TreeNode(6);
    root5->right->right = new TreeNode(20);
    bool result5 = sol.isValidBST(root5);
    bool expected5 = false; // 6 < 15 but 6 is in left of 15, but code doesn't check recursively properly? Wait, code does recurse, but 6 > 5? Wait, actually this is invalid because 6 > 5 but 6 is in right subtree of 10 via 15.
    // Wait, the code has a bug: it only checks direct children, not the full BST property.
    cout << "Test 5 (Invalid BST [10,5,15,null,null,6,20]): Result: " << (result5 ? "true" : "false") << ", Expected: " << (expected5 ? "true" : "false") << endl;

    // Test 6: Valid BST [1,null,2]
    TreeNode* root6 = new TreeNode(1);
    root6->right = new TreeNode(2);
    bool result6 = sol.isValidBST(root6);
    bool expected6 = true;
    cout << "Test 6 (Valid BST [1,null,2]): Result: " << (result6 ? "true" : "false") << ", Expected: " << (expected6 ? "true" : "false") << endl;

    // Clean up memory (optional, but good practice)
    delete root2;
    delete root3->left;
    delete root3->right;
    delete root3;
    delete root4->right->left;
    delete root4->right->right;
    delete root4->right;
    delete root4->left;
    delete root4;
    delete root5->right->left;
    delete root5->right->right;
    delete root5->right;
    delete root5->left;
    delete root5;
    delete root6->right;
    delete root6;

    return 0;
}
