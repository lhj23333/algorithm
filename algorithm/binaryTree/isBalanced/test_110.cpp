#include <iostream>
#include <cmath>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
    TreeNode(int val, TreeNode *left, TreeNode * right) : val(val), left(left), right(right) {}
};

class Solution {
private:
    int traversal(TreeNode *curNode) {
        if(curNode == nullptr) return 0;

        int leftHigh = traversal(curNode->left);
        if(leftHigh == -1) return -1;
        int rightHigh = traversal(curNode->right);
        if(rightHigh == -1) return -1;

        if(abs(leftHigh - rightHigh) > 1) return -1;

        return 1 + max(leftHigh, rightHigh);
    }

public:
    bool isBalanced(TreeNode *root) {
        if(root == nullptr) return true;

        return traversal(root) == -1 ? false : true;
    }
};

int main() {
    Solution sol;

    // Test 1: Balanced tree
    TreeNode* root1 = new TreeNode(1,
        new TreeNode(2,
            new TreeNode(4),
            new TreeNode(5)
        ),
        new TreeNode(3)
    );
    cout << "Test 1: " << sol.isBalanced(root1) << " (Expected: 1)" << endl;

    // Test 2: Unbalanced tree
    TreeNode* root2 = new TreeNode(1,
        new TreeNode(2,
            new TreeNode(3,
                new TreeNode(4),
                nullptr
            ),
            nullptr
        ),
        nullptr
    );
    cout << "Test 2: " << sol.isBalanced(root2) << " (Expected: 0)" << endl;

    // Test 3: Empty tree
    TreeNode* root3 = nullptr;
    cout << "Test 3: " << sol.isBalanced(root3) << " (Expected: 1)" << endl;

    // Test 4: Single node tree
    TreeNode* root4 = new TreeNode(1);
    cout << "Test 4: " << sol.isBalanced(root4) << " (Expected: 1)" << endl;

    // Test 5: Tree with only left children
    TreeNode* root5 = new TreeNode(1,
        new TreeNode(2,
            new TreeNode(3),
            nullptr
        ),
        nullptr
    );
    cout << "Test 5: " << sol.isBalanced(root5) << " (Expected: 0)" << endl;

    // Test 6: Tree with only right children
    TreeNode* root6 = new TreeNode(1,
        nullptr,
        new TreeNode(2,
            nullptr,
            new TreeNode(3)
        )
    );
    cout << "Test 6: " << sol.isBalanced(root6) << " (Expected: 0)" << endl;

    // Clean up memory (not strictly necessary for small tests)
    // ... (delete nodes if needed)
    return 0;
}
