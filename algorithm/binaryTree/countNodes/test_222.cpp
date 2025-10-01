#include <iostream>
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
    int traversal(TreeNode *curNode) {
        if(curNode == nullptr) return 0;

        int leftCount = traversal(curNode->left);
        int rightCount = traversal(curNode->right);

        return 1 + leftCount + rightCount;
    }

public:
    // // 1. 迭代法实现
    // int countNodes(TreeNode *root) {
    //     if(root == nullptr) return 0;
    //     queue<TreeNode*> que;
    //     int count = 0;

    //     que.push(root);
    //     while(!que.empty()) {
    //         size_t sizeQue = que.size();
    //         for(size_t i = 0; i < sizeQue; i ++) {
    //             TreeNode *curNode = que.front();
    //             que.pop();

    //             if(curNode->left != nullptr) que.push(curNode->left);
    //             if(curNode->right != nullptr) que.push(curNode->right);
    //         }
    //         count += sizeQue;
    //     }
    //     return count;
    // }

    // 2. 递归法实现
    int countNodes(TreeNode *root) {
        if(root == nullptr) return 0;
        
        return traversal(root);
    }
};

int main() {
    Solution sol;

    // Test case 1: Empty tree
    TreeNode* root1 = nullptr;
    cout << "Test 1: Expected = 0, Got = " << sol.countNodes(root1) << endl;

    // Test case 2: Single node
    TreeNode* root2 = new TreeNode(1);
    cout << "Test 2: Expected = 1, Got = " << sol.countNodes(root2) << endl;

    // Test case 3: Complete binary tree with 3 nodes
    TreeNode* root3 = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    cout << "Test 3: Expected = 3, Got = " << sol.countNodes(root3) << endl;

    // Test case 4: Complete binary tree with 6 nodes
    TreeNode* root4 = new TreeNode(1,
        new TreeNode(2, new TreeNode(4), new TreeNode(5)),
        new TreeNode(3, new TreeNode(6), nullptr)
    );
    cout << "Test 4: Expected = 6, Got = " << sol.countNodes(root4) << endl;

    // Test case 5: Complete binary tree with 7 nodes
    TreeNode* root5 = new TreeNode(1,
        new TreeNode(2, new TreeNode(4), new TreeNode(5)),
        new TreeNode(3, new TreeNode(6), new TreeNode(7))
    );
    cout << "Test 5: Expected = 7, Got = " << sol.countNodes(root5) << endl;

    // Test case 6: Left skewed tree
    TreeNode* root6 = new TreeNode(1, new TreeNode(2, new TreeNode(3), nullptr), nullptr);
    cout << "Test 6: Expected = 3, Got = " << sol.countNodes(root6) << endl;

    // Test case 7: Right skewed tree
    TreeNode* root7 = new TreeNode(1, nullptr, new TreeNode(2, nullptr, new TreeNode(3)));
    cout << "Test 7: Expected = 3, Got = " << sol.countNodes(root7) << endl;

    // Clean up (not strictly necessary for short tests, but good practice)
    // You can add code to delete the allocated nodes if needed.

    return 0;
}
