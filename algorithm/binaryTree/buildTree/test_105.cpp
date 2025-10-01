#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(), left(nullptr), right(nullptr) {}
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
    TreeNode(int val, TreeNode* left, TreeNode* right) : val(val), left(left), right(right) {}
};

class Solution {
private:
    TreeNode* traversal(vector<int> &preorder, vector<int> &inorder) {
        if(preorder.empty()) return {};

        int rootValue = preorder.front();
        TreeNode* root =  new TreeNode(rootValue);

        if(preorder.size() == 1) return root;

        size_t findRootIndex = 0;
        for(; findRootIndex < inorder.size(); findRootIndex++) {
            if(inorder[findRootIndex] == rootValue) break;
        }

        // 分割中序
        vector<int> leftInorder(inorder.begin(), inorder.begin() + findRootIndex);
        vector<int> rightInorder(inorder.begin() + findRootIndex + 1, inorder.end());

        vector<int> leftPreorder(preorder.begin() + 1, preorder.begin() + 1 + leftInorder.size());
        vector<int> rightPreorder(preorder.begin() + 1 + leftInorder.size(), preorder.end());

        root->left = traversal(leftPreorder, leftInorder);
        root->right = traversal(rightPreorder, rightInorder);

        return root;
    }

public:
    TreeNode* buildTree(vector<int> &preorder, vector<int> &inorder) {
        if(preorder.empty() || inorder.empty()) return {};
        return traversal(preorder, inorder);
    }
};  

void printTree(TreeNode* root) {
    // Preorder traversal print
    if (!root) return;
    cout << root->val << " ";
    printTree(root->left);
    printTree(root->right);
}

void printExpected(const vector<int>& preorder) {
    cout << "Expected preorder: ";
    for (int v : preorder) cout << v << " ";
    cout << endl;
}

int main() {
    Solution sol;

    // Test 1: Example tree
    vector<int> preorder1 = {3,9,20,15,7};
    vector<int> inorder1 = {9,3,15,20,7};
    TreeNode* tree1 = sol.buildTree(preorder1, inorder1);
    cout << "Test 1 result: ";
    printTree(tree1);
    cout << endl;
    printExpected(preorder1);

    // Test 2: Single node
    vector<int> preorder2 = {1};
    vector<int> inorder2 = {1};
    TreeNode* tree2 = sol.buildTree(preorder2, inorder2);
    cout << "Test 2 result: ";
    printTree(tree2);
    cout << endl;
    printExpected(preorder2);

    // Test 3: Left skewed
    vector<int> preorder3 = {1,2,3,4};
    vector<int> inorder3 = {4,3,2,1};
    TreeNode* tree3 = sol.buildTree(preorder3, inorder3);
    cout << "Test 3 result: ";
    printTree(tree3);
    cout << endl;
    printExpected(preorder3);

    // Test 4: Right skewed
    vector<int> preorder4 = {1,2,3,4};
    vector<int> inorder4 = {1,2,3,4};
    TreeNode* tree4 = sol.buildTree(preorder4, inorder4);
    cout << "Test 4 result: ";
    printTree(tree4);
    cout << endl;
    printExpected(preorder4);

    // Test 5: Empty tree
    vector<int> preorder5 = {};
    vector<int> inorder5 = {};
    TreeNode* tree5 = sol.buildTree(preorder5, inorder5);
    cout << "Test 5 result: ";
    printTree(tree5);
    cout << endl;
    printExpected(preorder5);

    // Test 6: Two nodes, right child
    vector<int> preorder6 = {1,2};
    vector<int> inorder6 = {1,2};
    TreeNode* tree6 = sol.buildTree(preorder6, inorder6);
    cout << "Test 6 result: ";
    printTree(tree6);
    cout << endl;
    printExpected(preorder6);

    // Test 7: Two nodes, left child
    vector<int> preorder7 = {1,2};
    vector<int> inorder7 = {2,1};
    TreeNode* tree7 = sol.buildTree(preorder7, inorder7);
    cout << "Test 7 result: ";
    printTree(tree7);
    cout << endl;
    printExpected(preorder7);

    return 0;
}
