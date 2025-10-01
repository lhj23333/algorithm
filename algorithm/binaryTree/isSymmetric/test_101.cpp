#include <iostream>
#include <deque>

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
    bool compare(TreeNode *left, TreeNode *right) {
        if(left == nullptr && right == nullptr) return true;
        if((left != nullptr) != (right != nullptr)) return false;
        if(left->val != right->val) return false;

        bool outSider = compare(left->left, right->right);
        bool inSider = compare(left->right, right->left);

        return outSider && inSider;
    }

public:
    // 1. 迭代法
    // bool isSymmetric(TreeNode *root) {
    //     if(root == nullptr) return true;
    //     deque<TreeNode*> dq;
        
    //     dq.push_front(root->left);
    //     dq.push_back(root->right);
    //     while(!dq.empty()) {
    //         TreeNode *left = dq.front(); dq.pop_front();
    //         TreeNode *right = dq.back(); dq.pop_back();

    //         if(left == nullptr && right == nullptr) continue;
    //         if((left == nullptr) != (right == nullptr)) return false;
    //         if(left->val != right->val) return false;

    //         dq.push_front(left->left);
    //         dq.push_back(right->right);
    //         dq.push_front(left->right);
    //         dq.push_back(right->left);
    //     }
    //     return true;
    // }

    // 2. 递归法
    bool isSymmetric(TreeNode *root) {
        if(root == nullptr) return true;
        return compare(root->left, root->right);
    }
};

int main()
{
    Solution sol;

    // 对称二叉树
    TreeNode* root1 = new TreeNode(1,
        new TreeNode(2, new TreeNode(3), new TreeNode(4)),
        new TreeNode(2, new TreeNode(4), new TreeNode(3))
    );
    cout << "Test 1 (Symmetric): " << (sol.isSymmetric(root1) ? "Passed" : "Failed") << endl;

    // 非对称二叉树
    TreeNode* root2 = new TreeNode(1,
        new TreeNode(2, nullptr, new TreeNode(3)),
        new TreeNode(2, nullptr, new TreeNode(3))
    );
    cout << "Test 2 (Not Symmetric): " << (!sol.isSymmetric(root2) ? "Passed" : "Failed") << endl;

    // 空树
    TreeNode* root3 = nullptr;
    cout << "Test 3 (Empty Tree): " << (sol.isSymmetric(root3) ? "Passed" : "Failed") << endl;

    // 单节点树
    TreeNode* root4 = new TreeNode(1);
    cout << "Test 4 (Single Node): " << (sol.isSymmetric(root4) ? "Passed" : "Failed") << endl;

    return 0;
}