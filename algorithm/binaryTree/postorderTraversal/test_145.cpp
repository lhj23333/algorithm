#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

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
        if(curNode == nullptr) return ;

        traversal(curNode->left, res);
        traversal(curNode->right, res);
        res->push_back(curNode->val);
    }

public:
    // // 1. 递归法
    // vector<int> postorderTraversal(TreeNode *root) {
    //     if(root == nullptr) return {};
    //     vector<int> result;

    //     traversal(root, &result);

    //     return result;
    // }

    // 2. 迭代法
    vector<int> postorderTraversal(TreeNode *root) {
        stack<TreeNode*> st;
        vector<int> result;

        st.push(root);
        while(!st.empty()) {
            TreeNode *curNode = st.top();
            st.pop();

            if(curNode != nullptr) result.push_back(curNode->val);
            else continue;

            st.push(curNode->left);
            st.push(curNode->right);
        }
        reverse(result.begin(), result.end());
        
        return result;
    }
};

// Helper function to build a binary tree
TreeNode* buildTree(const vector<int>& nodes, int& idx) {
    if (idx >= nodes.size() || nodes[idx] == -1) {
        idx++;
        return nullptr;
    }
    TreeNode* root = new TreeNode(nodes[idx++]);
    root->left = buildTree(nodes, idx);
    root->right = buildTree(nodes, idx);
    return root;
}

int main() {
    Solution sol;

    // Test 1: Empty tree
    TreeNode* root1 = nullptr;
    vector<int> res1 = sol.postorderTraversal(root1);
    cout << "Test 1: ";
    for (int v : res1) cout << v << " ";
    cout << "(Expected: )" << endl;

    // Test 2: Single node
    TreeNode* root2 = new TreeNode(1);
    vector<int> res2 = sol.postorderTraversal(root2);
    cout << "Test 2: ";
    for (int v : res2) cout << v << " ";
    cout << "(Expected: 1)" << endl;

    // Test 3: Complete binary tree [1,2,3]
    //      1
    //     / \
    //    2   3
    int idx3 = 0;
    TreeNode* root3 = buildTree({1,2,-1,-1,3,-1,-1}, idx3);
    vector<int> res3 = sol.postorderTraversal(root3);
    cout << "Test 3: ";
    for (int v : res3) cout << v << " ";
    cout << "(Expected: 2 3 1)" << endl;

    // Test 4: Left skewed tree [1,2,3]
    //    1
    //   /
    //  2
    // /postorderTraversal
    //3
    int idx4 = 0;
    TreeNode* root4 = buildTree({1,2,3,-1,-1,-1,-1}, idx4);
    vector<int> res4 = sol.postorderTraversal(root4);
    cout << "Test 4: ";
    for (int v : res4) cout << v << " ";
    cout << "(Expected: 3 2 1)" << endl;

    // Test 5: Right skewed tree [1,null,2,null,3]
    // 1
    //  \
    //   2
    //    \
    //     3
    int idx5 = 0;
    TreeNode* root5 = buildTree({1,-1,2,-1,3,-1,-1}, idx5);
    vector<int> res5 = sol.postorderTraversal(root5);
    cout << "Test 5: ";
    for (int v : res5) cout << v << " ";
    cout << "(Expected: 3 2 1)" << endl;

    // Test 6: More complex tree [1,2,4,null,null,5,null,null,3]
    //      1
    //     / \
    //    2   3
    //   / \
    //  4   5
    int idx6 = 0;
    TreeNode* root6 = buildTree({1,2,4,-1,-1,5,-1,-1,3,-1,-1}, idx6);
    vector<int> res6 = sol.postorderTraversal(root6);
    cout << "Test 6: ";
    for (int v : res6) cout << v << " ";
    cout << "(Expected: 4 5 2 3 1)" << endl;
}
