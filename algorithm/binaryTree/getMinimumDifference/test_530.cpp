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
    int minimum = INT_MAX;
    
    void traversal(TreeNode *curNode) {
        if(curNode == nullptr) return ;

        traversal(curNode->left);
        
        if((!vec.empty())) minimum = min(minimum, abs(curNode->val - vec.back()));
        vec.push_back(curNode->val);
        
        traversal(curNode->right);
    }

public:
    int getMinimumDifference(TreeNode *root) {
        if(root == nullptr) return 0;
        traversal(root);
        return minimum;
    }
};

// Helper function to build a BST from a vector (for simplicity, assuming sorted input)
TreeNode* buildBST(const vector<int>& nums, int start, int end) {
    if (start > end) return nullptr;
    int mid = start + (end - start) / 2;
    TreeNode* root = new TreeNode(nums[mid]);
    root->left = buildBST(nums, start, mid - 1);
    root->right = buildBST(nums, mid + 1, end);
    return root;
}

// Helper function to delete the tree
void deleteTree(TreeNode* root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    Solution sol;
    
    // Test Case 1: Basic BST with small differences
    vector<int> nums1 = {1, 3, 5, 7, 9};
    TreeNode* root1 = buildBST(nums1, 0, nums1.size() - 1);
    int result1 = sol.getMinimumDifference(root1);
    int expected1 = 2; // Differences: 3-1=2, 5-3=2, 7-5=2, 9-7=2
    cout << "Test 1 - Result: " << result1 << ", Expected: " << expected1 << endl;
    deleteTree(root1);
    
    // Test Case 2: BST with larger differences
    vector<int> nums2 = {10, 20, 30, 40, 50};
    TreeNode* root2 = buildBST(nums2, 0, nums2.size() - 1);
    int result2 = sol.getMinimumDifference(root2);
    int expected2 = 10; // Differences: 20-10=10, 30-20=10, etc.
    cout << "Test 2 - Result: " << result2 << ", Expected: " << expected2 << endl;
    deleteTree(root2);
    
    // Test Case 3: Single node
    TreeNode* root3 = new TreeNode(5);
    int result3 = sol.getMinimumDifference(root3);
    int expected3 = INT_MAX; // No differences, should return INT_MAX or 0? Wait, code returns 0 for null, but for single node, minimum remains INT_MAX, but function returns minimum which is INT_MAX
    cout << "Test 3 - Result: " << result3 << ", Expected: " << expected3 << endl;
    deleteTree(root3);
    
    // Test Case 4: Two nodes
    TreeNode* root4 = new TreeNode(1);
    root4->right = new TreeNode(3);
    int result4 = sol.getMinimumDifference(root4);
    int expected4 = 2; // Difference: 3-1=2
    cout << "Test 4 - Result: " << result4 << ", Expected: " << expected4 << endl;
    deleteTree(root4);
    
    // Test Case 5: Null root
    TreeNode* root5 = nullptr;
    int result5 = sol.getMinimumDifference(root5);
    int expected5 = 0; // As per code
    cout << "Test 5 - Result: " << result5 << ", Expected: " << expected5 << endl;
    
    // Test Case 6: Larger BST with mixed differences
    vector<int> nums6 = {4, 2, 6, 1, 3, 5, 7};
    TreeNode* root6 = buildBST(nums6, 0, nums6.size() - 1);
    int result6 = sol.getMinimumDifference(root6);
    int expected6 = 1; // Inorder: 1,2,3,4,5,6,7 -> min diff 1
    cout << "Test 6 - Result: " << result6 << ", Expected: " << expected6 << endl;
    deleteTree(root6);
    
    return 0;
}