#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
    TreeNode(int val, TreeNode* left, TreeNode* right) : val(val), left(left), right(right) {}
};

class Solution {
private:
    TreeNode *traversal(vector<int> &nums) {
        if(nums.empty()) return nullptr;
        
        int max = INT_MIN;
        for(size_t i = 0; i < nums.size(); i ++) {
            max = nums[i] > max ? nums[i] : max;
        }
        size_t maxNodeIndex = 0;
        for(; maxNodeIndex < nums.size(); maxNodeIndex ++) {
            if(nums[maxNodeIndex] == max) break;
        }
        TreeNode *root = new TreeNode(nums[maxNodeIndex]);
        
        if(nums.size() == 1) return root;

        vector<int> leftNums(nums.begin(), nums.begin() + maxNodeIndex);
        vector<int> rightNums(nums.begin() + maxNodeIndex + 1, nums.end());
        
        root->left = traversal(leftNums);
        root->right = traversal(rightNums);

        return root;
    };

public:
    TreeNode *constructMaximumBinaryTree(vector<int> &nums){
        if(nums.empty()) return {};
        return traversal(nums);
    }
};

// Helper function to print inorder traversal
void printInorder(TreeNode* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

// Helper function to print the tree in preorder (for structure verification)
void printPreorder(TreeNode* root) {
    if (!root) {
        cout << "null ";
        return;
    }
    cout << root->val << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

int main() {
    Solution sol;
    
    // Test case 1: Standard example
    vector<int> nums1 = {3, 2, 1, 6, 0, 5};
    TreeNode* root1 = sol.constructMaximumBinaryTree(nums1);
    cout << "Test 1 - Input: ";
    for (int num : nums1) cout << num << " ";
    cout << endl;
    cout << "Constructed Inorder: ";
    printInorder(root1);
    cout << endl;
    cout << "Correct Inorder: ";
    for (int num : nums1) cout << num << " ";
    cout << endl;
    cout << "Constructed Preorder: ";
    printPreorder(root1);
    cout << endl;
    cout << "Correct Preorder: 6 3 2 1 null null 0 null null null 5 null null" << endl;
    cout << endl;
    
    // Test case 2: Increasing order
    vector<int> nums2 = {1, 2, 3};
    TreeNode* root2 = sol.constructMaximumBinaryTree(nums2);
    cout << "Test 2 - Input: ";
    for (int num : nums2) cout << num << " ";
    cout << endl;
    cout << "Constructed Inorder: ";
    printInorder(root2);
    cout << endl;
    cout << "Correct Inorder: ";
    for (int num : nums2) cout << num << " ";
    cout << endl;
    cout << "Constructed Preorder: ";
    printPreorder(root2);
    cout << endl;
    cout << "Correct Preorder: 3 2 1 null null null null" << endl;
    cout << endl;
    
    // Test case 3: Single element
    vector<int> nums3 = {5};
    TreeNode* root3 = sol.constructMaximumBinaryTree(nums3);
    cout << "Test 3 - Input: ";
    for (int num : nums3) cout << num << " ";
    cout << endl;
    cout << "Constructed Inorder: ";
    printInorder(root3);
    cout << endl;
    cout << "Correct Inorder: ";
    for (int num : nums3) cout << num << " ";
    cout << endl;
    cout << "Constructed Preorder: ";
    printPreorder(root3);
    cout << endl;
    cout << "Correct Preorder: 5 null null" << endl;
    cout << endl;
    
    // Test case 4: Two elements
    vector<int> nums4 = {1, 2};
    TreeNode* root4 = sol.constructMaximumBinaryTree(nums4);
    cout << "Test 4 - Input: ";
    for (int num : nums4) cout << num << " ";
    cout << endl;
    cout << "Constructed Inorder: ";
    printInorder(root4);
    cout << endl;
    cout << "Correct Inorder: ";
    for (int num : nums4) cout << num << " ";
    cout << endl;
    cout << "Constructed Preorder: ";
    printPreorder(root4);
    cout << endl;
    cout << "Correct Preorder: 2 1 null null null" << endl;
    cout << endl;
    
    // Test case 5: Empty vector
    vector<int> nums5 = {};
    TreeNode* root5 = sol.constructMaximumBinaryTree(nums5);
    cout << "Test 5 - Input: (empty)" << endl;
    cout << "Constructed Inorder: ";
    printInorder(root5);
    cout << endl;
    cout << "Correct Inorder: (empty)" << endl;
    cout << "Constructed Preorder: ";
    printPreorder(root5);
    cout << endl;
    cout << "Correct Preorder: null" << endl;
    cout << endl;
    
    // Test case 6: All same elements
    vector<int> nums6 = {2, 2, 2};
    TreeNode* root6 = sol.constructMaximumBinaryTree(nums6);
    cout << "Test 6 - Input: ";
    for (int num : nums6) cout << num << " ";
    cout << endl;
    cout << "Constructed Inorder: ";
    printInorder(root6);
    cout << endl;
    cout << "Correct Inorder: ";
    for (int num : nums6) cout << num << " ";
    cout << endl;
    cout << "Constructed Preorder: ";
    printPreorder(root6);
    cout << endl;
    cout << "Correct Preorder: 2 2 null 2 null null null" << endl;  // Since first max is at index 0
    cout << endl;
    
    return 0;
}
