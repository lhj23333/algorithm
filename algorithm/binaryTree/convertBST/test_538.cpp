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
private:
    int sum;

    void traversal(TreeNode *curNode) {
        if(curNode == nullptr) return ;

        if(curNode->right != nullptr) traversal(curNode->right);
        sum += curNode->val;
        curNode->val = sum;
        if(curNode->left != nullptr) traversal(curNode->left);
    };

public:
    TreeNode *convertBST(TreeNode *root) {
        if(root == nullptr) return nullptr;
        
        sum = 0;
        traversal(root);

        return root;
    }
};

static void inorderCollect(TreeNode* root, vector<int>& out) {
    if (!root) return;
    inorderCollect(root->left, out);
    out.push_back(root->val);
    inorderCollect(root->right, out);
}

static void printVec(const vector<int>& v) {
    cout << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        if (i) cout << ", ";
        cout << v[i];
    }
    cout << "]";
}

int main() {
    Solution sol;

    // Test 1: empty tree
    {
        TreeNode* root = nullptr;
        TreeNode* res = sol.convertBST(root);
        vector<int> out;
        inorderCollect(res, out);
        cout << "Test 1 (empty): result inorder: ";
        printVec(out);
        cout << "  expected inorder: []\n";
    }

    // Test 2: single node [5] -> expected [5]
    {
        TreeNode* root = new TreeNode(5);
        TreeNode* res = sol.convertBST(root);
        vector<int> out;
        inorderCollect(res, out);
        cout << "Test 2 (single): result inorder: ";
        printVec(out);
        cout << "  expected inorder: [5]\n";
        delete root;
    }

    // Test 3: right-skewed 2 -> 3  (inorder original [2,3]) -> expected inorder [5,3]
    {
        TreeNode* root = new TreeNode(2, nullptr, new TreeNode(3));
        TreeNode* res = sol.convertBST(root);
        vector<int> out;
        inorderCollect(res, out);
        cout << "Test 3 (right-skewed): result inorder: ";
        printVec(out);
        cout << "  expected inorder: [5, 3]\n";
        // free
        delete root->right;
        delete root;
    }

    // Test 4: left-skewed 3 <- 2 <- 1 (inorder original [1,2,3]) -> expected inorder [6,5,3]
    {
        TreeNode* root = new TreeNode(3, new TreeNode(2, new TreeNode(1), nullptr), nullptr);
        TreeNode* res = sol.convertBST(root);
        vector<int> out;
        inorderCollect(res, out);
        cout << "Test 4 (left-skewed): result inorder: ";
        printVec(out);
        cout << "  expected inorder: [6, 5, 3]\n";
        // free
        delete root->left->left;
        delete root->left;
        delete root;
    }

    // Test 5: larger balanced example (LeetCode example)
    // original tree level-order:
    // [4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]
    // expected converted level-order:
    // [30,36,21,36,35,26,15,null,null,null,33,null,null,null,8]
    {
        TreeNode* n0 = new TreeNode(0);
        TreeNode* n3 = new TreeNode(3);
        TreeNode* n2 = new TreeNode(2, nullptr, n3);
        TreeNode* n1 = new TreeNode(1, n0, n2);
        TreeNode* n5 = new TreeNode(5);
        TreeNode* n8 = new TreeNode(8);
        TreeNode* n7 = new TreeNode(7, nullptr, n8);
        TreeNode* n6 = new TreeNode(6, n5, n7);
        TreeNode* root = new TreeNode(4, n1, n6);

        Solution sol2;
        TreeNode* res = sol2.convertBST(root);
        vector<int> out;
        inorderCollect(res, out);
        cout << "Test 5 (balanced example): result inorder: ";
        printVec(out);
        cout << "  expected inorder: [36, 36, 35, 33, 30, 26, 21, 15, 8]\n";

        // free nodes
        delete n0; delete n3; delete n2; delete n1;
        delete n5; delete n8; delete n7; delete n6; delete root;
    }

    return 0;
}