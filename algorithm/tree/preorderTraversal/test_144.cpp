#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *leftNode;
    TreeNode *rightNode;    
    TreeNode() : val(0), leftNode(nullptr), rightNode(nullptr) {}
    TreeNode(int val) : val(val), leftNode(nullptr), rightNode(nullptr) {}
    TreeNode(int val, TreeNode *left, TreeNode *right) : val(val), leftNode(left), rightNode(right) {}
};

class Solution {
private:
    void traversal(TreeNode *curNode, vector<int> *ret) {
        if(curNode == nullptr) return ;

        ret->push_back(curNode->val);
        traversal(curNode->leftNode, ret);
        traversal(curNode->rightNode, ret);
    }

public:
    vector<int> preorderTraversal(TreeNode *root) {
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
    vector<int> res1 = sol.preorderTraversal(root1);
    cout << "Test 1: ";
    for (int v : res1) cout << v << " ";
    cout << endl;

    // Test 2: Single node tree
    TreeNode* root2 = new TreeNode(1);
    vector<int> res2 = sol.preorderTraversal(root2);
    cout << "Test 2: ";
    for (int v : res2) cout << v << " ";
    cout << endl;

    // Test 3: Tree with left child only
    TreeNode* root3 = new TreeNode(1, new TreeNode(2), nullptr);
    vector<int> res3 = sol.preorderTraversal(root3);
    cout << "Test 3: ";
    for (int v : res3) cout << v << " ";
    cout << endl;

    // Test 4: Tree with right child only
    TreeNode* root4 = new TreeNode(1, nullptr, new TreeNode(3));
    vector<int> res4 = sol.preorderTraversal(root4);
    cout << "Test 4: ";
    for (int v : res4) cout << v << " ";
    cout << endl;

    // Test 5: Complete binary tree
    TreeNode* root5 = new TreeNode(1,
        new TreeNode(2, new TreeNode(4), new TreeNode(5)),
        new TreeNode(3, new TreeNode(6), new TreeNode(7))
    );
    vector<int> res5 = sol.preorderTraversal(root5);
    cout << "Test 5: ";
    for (int v : res5) cout << v << " ";
    cout << endl;

    // Test 6: Skewed tree (all left)
    TreeNode* root6 = new TreeNode(1, new TreeNode(2, new TreeNode(3), nullptr), nullptr);
    vector<int> res6 = sol.preorderTraversal(root6);
    cout << "Test 6: ";
    for (int v : res6) cout << v << " ";
    cout << endl;

    // Test 7: Skewed tree (all right)
    TreeNode* root7 = new TreeNode(1, nullptr, new TreeNode(2, nullptr, new TreeNode(3)));
    vector<int> res7 = sol.preorderTraversal(root7);
    cout << "Test 7: ";
    for (int v : res7) cout << v << " ";
    cout << endl;
}