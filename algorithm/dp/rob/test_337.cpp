#include <iostream>
#include <vector>
#include <unordered_map>

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
    unordered_map<TreeNode *, int> umap;

    // 1. 暴力：
    int traversal(TreeNode *curNode) {
        if(curNode == nullptr) return 0;
        if(umap[curNode]) return umap[curNode];

        int val1 = curNode->val;
        if(curNode->left != nullptr) val1 += traversal(curNode->left->left) + traversal(curNode->left->right);
        if(curNode->right != nullptr) val1 += traversal(curNode->right->left) + traversal(curNode->right->right);

        int val2 = traversal(curNode->left) + traversal(curNode->right);
        umap[curNode] = max(val1, val2);
        return max(val1, val2);
    }

    // 2. dp
    vector<int> robTree(TreeNode *curNode) {
        if(curNode == nullptr) return vector<int> {0, 0};

        vector<int> left = robTree(curNode->left);
        vector<int> right = robTree(curNode->right);

        int val1 = curNode->val + left[0] + right[0]; // 偷
        int val2 = max(left[0], left[1]) + max(right[0], right[1]); // 不偷
        return {val2, val1};
    }

public:
    int rob(TreeNode *root) {
        if(root == nullptr) return 0;
        if(root->left == nullptr && root->right == nullptr) return root->val;
        // return traversal(root);
        vector<int> result = robTree(root);
        return max(result[0], result[1]);
    }
};

int main() {
    Solution solution;
    
    // Test case 1: Empty tree
    TreeNode* root1 = nullptr;
    cout << "Test 1 (empty tree): " << solution.rob(root1) << " (expected: 0)" << endl;
    
    // Test case 2: Single node
    TreeNode* root2 = new TreeNode(5);
    cout << "Test 2 (single node): " << solution.rob(root2) << " (expected: 5)" << endl;
    
    // Test case 3: Example [3,2,3,null,3,null,1]
    TreeNode* root3 = new TreeNode(3);
    root3->left = new TreeNode(2);
    root3->right = new TreeNode(3);
    root3->left->right = new TreeNode(3);
    root3->right->right = new TreeNode(1);
    cout << "Test 3 ([3,2,3,null,3,null,1]): " << solution.rob(root3) << " (expected: 7)" << endl;
    
    // Test case 4: Example [3,4,5,1,3,null,1]
    TreeNode* root4 = new TreeNode(3);
    root4->left = new TreeNode(4);
    root4->right = new TreeNode(5);
    root4->left->left = new TreeNode(1);
    root4->left->right = new TreeNode(3);
    root4->right->right = new TreeNode(1);
    cout << "Test 4 ([3,4,5,1,3,null,1]): " << solution.rob(root4) << " (expected: 9)" << endl;
    
    // Test case 5: Linear tree (left skewed)
    TreeNode* root5 = new TreeNode(4);
    root5->left = new TreeNode(1);
    root5->left->left = new TreeNode(2);
    root5->left->left->left = new TreeNode(3);
    cout << "Test 5 (left skewed): " << solution.rob(root5) << " (expected: 7)" << endl;
    
    // Test case 6: Linear tree (right skewed)
    TreeNode* root6 = new TreeNode(1);
    root6->right = new TreeNode(2);
    root6->right->right = new TreeNode(3);
    root6->right->right->right = new TreeNode(4);
    cout << "Test 6 (right skewed): " << solution.rob(root6) << " (expected: 5)" << endl;
    
    // Test case 7: Complete binary tree with 3 levels
    TreeNode* root7 = new TreeNode(10);
    root7->left = new TreeNode(5);
    root7->right = new TreeNode(6);
    root7->left->left = new TreeNode(1);
    root7->left->right = new TreeNode(3);
    root7->right->left = new TreeNode(2);
    root7->right->right = new TreeNode(4);
    cout << "Test 7 (complete tree): " << solution.rob(root7) << " (expected: 20)" << endl;
    
    return 0;
}
