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
private:
    bool result = false;
    int sum;

    void traversial(TreeNode *curNode, int targetSum) {
        if((curNode->left == nullptr) && (curNode->right == nullptr) && (sum == targetSum)) {
            result = true;
        }

        if(curNode->left != nullptr) {
            sum += curNode->left->val;
            traversial(curNode->left, targetSum);
            sum -= curNode->left->val;
        }
        if(curNode->right != nullptr) {
            sum += curNode->right->val;
            traversial(curNode->right, targetSum);
            sum -= curNode->right->val; 
        } 
    }

public:
    bool hasPathSum(TreeNode *root, int targetSum) {
        if(root == nullptr) return false;
        sum = root->val;
    
        traversial(root, targetSum);
        
        return result;
    }
};

// Helper function to build a binary tree
TreeNode* buildTree() {
    // Example tree:
    //      5
    //     / \
    //    4   8
    //   /   / \
    //  11  13  4
    // /  \      \
    //7    2      1
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->right = new TreeNode(1);
    return root;
}

int main()
{
    Solution sol;

    // Test 1: Path sum exists
    TreeNode* root1 = buildTree();
    int targetSum1 = 22;
    bool result1 = sol.hasPathSum(root1, targetSum1);
    cout << "Test 1: hasPathSum(root1, 22) = " << result1 << ", expected: true" << endl;

    // Test 2: Path sum does not exist
    Solution sol2;
    int targetSum2 = 26;
    bool result2 = sol2.hasPathSum(root1, targetSum2);
    cout << "Test 2: hasPathSum(root1, 26) = " << result2 << ", expected: true" << endl;

    // Test 3: Empty tree
    Solution sol3;
    TreeNode* root2 = nullptr;
    int targetSum3 = 0;
    bool result3 = sol3.hasPathSum(root2, targetSum3);
    cout << "Test 3: hasPathSum(nullptr, 0) = " << result3 << ", expected: false" << endl;

    // Test 4: Single node equals targetSum
    Solution sol4;
    TreeNode* root3 = new TreeNode(7);
    int targetSum4 = 7;
    bool result4 = sol4.hasPathSum(root3, targetSum4);
    cout << "Test 4: hasPathSum(single node 7, 7) = " << result4 << ", expected: true" << endl;

    // Test 5: Single node not equals targetSum
    Solution sol5;
    int targetSum5 = 8;
    bool result5 = sol5.hasPathSum(root3, targetSum5);
    cout << "Test 5: hasPathSum(single node 7, 8) = " << result5 << ", expected: false" << endl;

    // Clean up
    // (In production code, you should delete all allocated nodes to avoid memory leaks)
}