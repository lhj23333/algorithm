#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
    TreeNode(int val, TreeNode* left, TreeNode* right) : val(val), left(left), right(right) {} 
};

class Solution {
private:
    // int traversal(TreeNode *curNode) {
    //     if((curNode->left == nullptr) && (curNode->right == nullptr)) return 1;
    //     int leftHigh = curNode->left == nullptr ? INT_MAX : traversal(curNode->left);
    //     int rightHigh = curNode->right == nullptr ? INT_MAX : traversal(curNode->right);
    //     return 1 + min(leftHigh, rightHigh);
    // }

    int traversal(TreeNode *curNode) {
        if(curNode == nullptr) return 0;
        int leftDepth = traversal(curNode->left);
        int rightDepth = traversal(curNode->right);
        return 1 + min(leftDepth, rightDepth);
    }

public:
    // // 1. 迭代法实现
    // int minDepth(TreeNode *root) {
    //     if(root == nullptr) return 1;
    //     queue<TreeNode*> que;
    //     int level = 1;

    //     que.push(root);
    //     while(!que.empty()) {
    //         size_t sizeQue = que.size();
    //         for(size_t i = 0; i < sizeQue; i ++) {
    //             TreeNode *curNode = que.front();
    //             que.pop();

    //             if((curNode->left == nullptr) && (curNode->right == nullptr)) return level;
    //             if(curNode->left != nullptr) que.push(curNode->left);
    //             if(curNode->right != nullptr) que.push(curNode->right);
    //         }
    //         level ++;
    //     }
    //     return level; 
    // }

    // 2. 递归法实现
    int minDepth(TreeNode *root) {
        if(root == nullptr) return 0;
        
        if((root->left == nullptr) || (root->right == nullptr)) {
            if(root->left == nullptr) return 1 + traversal(root->right);
            else return 1 + traversal(root->left);
        }

        return traversal(root);
    }
};

int main() {
    Solution sol;

    // Test 1: Empty tree
    TreeNode* root1 = nullptr;
    cout << "Test 1: " << sol.minDepth(root1) << " // Expected: 0" << endl;

    // Test 2: Single node tree
    TreeNode* root2 = new TreeNode(1);
    cout << "Test 2: " << sol.minDepth(root2) << " // Expected: 1" << endl;

    // Test 3: Two-level tree, left child only
    TreeNode* root3 = new TreeNode(1, new TreeNode(2), nullptr);
    cout << "Test 3: " << sol.minDepth(root3) << " // Expected: 2" << endl;

    // Test 4: Two-level tree, right child only
    TreeNode* root4 = new TreeNode(1, nullptr, new TreeNode(3));
    cout << "Test 4: " << sol.minDepth(root4) << " // Expected: 2" << endl;

    // Test 5: Three-level tree, left subtree is deeper
    TreeNode* root5 = new TreeNode(1,
        new TreeNode(2, new TreeNode(4), nullptr),
        new TreeNode(3)
    );
    cout << "Test 5: " << sol.minDepth(root5) << " // Expected: 2" << endl;

    // Test 6: Balanced tree
    TreeNode* root6 = new TreeNode(1,
        new TreeNode(2, new TreeNode(4), new TreeNode(5)),
        new TreeNode(3, new TreeNode(6), new TreeNode(7))
    );
    cout << "Test 6: " << sol.minDepth(root6) << " // Expected: 3" << endl;

    // Test 7: Unbalanced tree, minimum depth on right
    TreeNode* root7 = new TreeNode(1,
        new TreeNode(2, new TreeNode(4, new TreeNode(8), nullptr), nullptr),
        new TreeNode(3)
    );
    cout << "Test 7: " << sol.minDepth(root7) << " // Expected: 2" << endl;
}
