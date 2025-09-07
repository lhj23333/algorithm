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
    void traversal(TreeNode *curNode, vector<int> *res) {
        if(curNode == nullptr) return;

        traversal(curNode->left, res);
        res->push_back(curNode->val);
        traversal(curNode->right, res);
    }

public:
    vector<int> inorderTraversal(TreeNode *root) {
        if(root == nullptr) return {};
        vector<int> result;

        traversal(root, &result);
        return result;
    }
};

int main()
{
    // Test 1: Empty tree
    Solution sol;
    TreeNode* root1 = nullptr;
    vector<int> res1 = sol.inorderTraversal(root1);
    cout << "Test 1 (Empty tree): ";
    for (int v : res1) cout << v << " ";
    cout << endl; // Expected output: (empty line)

    // Test 2: Single node tree
    TreeNode* root2 = new TreeNode(1);
    vector<int> res2 = sol.inorderTraversal(root2);
    cout << "Test 2 (Single node): ";
    for (int v : res2) cout << v << " ";
    cout << endl; // Expected output: 1

    // Test 3: Left-skewed tree
    TreeNode* root3 = new TreeNode(3, new TreeNode(2, new TreeNode(1), nullptr), nullptr);
    vector<int> res3 = sol.inorderTraversal(root3);
    cout << "Test 3 (Left-skewed): ";
    for (int v : res3) cout << v << " ";
    cout << endl; // Expected output: 1 2 3

    // Test 4: Right-skewed tree
    TreeNode* root4 = new TreeNode(1, nullptr, new TreeNode(2, nullptr, new TreeNode(3)));
    vector<int> res4 = sol.inorderTraversal(root4);
    cout << "Test 4 (Right-skewed): ";
    for (int v : res4) cout << v << " ";
    cout << endl; // Expected output: 1 2 3

    // Test 5: Balanced tree
    TreeNode* root5 = new TreeNode(2, new TreeNode(1), new TreeNode(3));
    vector<int> res5 = sol.inorderTraversal(root5);
    cout << "Test 5 (Balanced): ";
    for (int v : res5) cout << v << " ";
    cout << endl; // Expected output: 1 2 3

    // Test 6: Complex tree
    TreeNode* root6 = new TreeNode(4,
        new TreeNode(2, new TreeNode(1), new TreeNode(3)),
        new TreeNode(6, new TreeNode(5), new TreeNode(7))
    );
    vector<int> res6 = sol.inorderTraversal(root6);
    cout << "Test 6 (Complex): ";
    for (int v : res6) cout << v << " ";
    cout << endl; // Expected output: 1 2 3 4 5 6 7
}