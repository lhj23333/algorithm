#include <iostream>

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
    int result;

    // 0 -> 未覆盖，1 -> 摄像头，2 -> 已覆盖
    int traversal(TreeNode *curNode) {
        if(curNode == nullptr) return 2;

        int left = traversal(curNode->left);
        int right = traversal(curNode->right);

        if(left == 0 || right == 0) {
            result ++;
            return 1;
        } else {
            if(left == 1 || right == 1) return 2;
            else {
                if(left == 2 || right == 2) return 0;
            }
        }
        
        return -1;
    }

public:
    int minCameraCover(TreeNode *root) {
        result = 0;
        if(traversal(root) == 0) {
            result ++;
        }
        return result;
    }
};

int main() {
    Solution solution;
    
    // Test case 1: Single node
    TreeNode* root1 = new TreeNode(0);
    cout << "Test 1 - Single node: " << solution.minCameraCover(root1) << " (Expected: 1)" << endl;
    
    // Test case 2: Linear tree (left skewed)
    TreeNode* root2 = new TreeNode(0);
    root2->left = new TreeNode(0);
    root2->left->left = new TreeNode(0);
    cout << "Test 2 - Left skewed tree: " << solution.minCameraCover(root2) << " (Expected: 1)" << endl;
    
    // Test case 3: Linear tree (right skewed)
    TreeNode* root3 = new TreeNode(0);
    root3->right = new TreeNode(0);
    root3->right->right = new TreeNode(0);
    cout << "Test 3 - Right skewed tree: " << solution.minCameraCover(root3) << " (Expected: 1)" << endl;
    
    // Test case 4: Complete binary tree with 3 nodes
    TreeNode* root4 = new TreeNode(0);
    root4->left = new TreeNode(0);
    root4->right = new TreeNode(0);
    cout << "Test 4 - Complete tree (3 nodes): " << solution.minCameraCover(root4) << " (Expected: 1)" << endl;
    
    // Test case 5: Larger complete binary tree
    TreeNode* root5 = new TreeNode(0);
    root5->left = new TreeNode(0);
    root5->right = new TreeNode(0);
    root5->left->left = new TreeNode(0);
    root5->left->right = new TreeNode(0);
    root5->right->left = new TreeNode(0);
    root5->right->right = new TreeNode(0);
    cout << "Test 5 - Complete tree (7 nodes): " << solution.minCameraCover(root5) << " (Expected: 2)" << endl;
    
    // Test case 6: Unbalanced tree
    TreeNode* root6 = new TreeNode(0);
    root6->left = new TreeNode(0);
    root6->left->left = new TreeNode(0);
    root6->left->right = new TreeNode(0);
    root6->right = new TreeNode(0);
    cout << "Test 6 - Unbalanced tree: " << solution.minCameraCover(root6) << " (Expected: 2)" << endl;
    
    return 0;
}
