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
    TreeNode *findNode;
    int maxDepth = INT_MIN;

    void traversial(TreeNode *curNode, int depth) {
        if((curNode->left == nullptr) && (curNode->right == nullptr)) {
            if(depth > maxDepth) {
                maxDepth = depth;
                findNode = curNode;
            }
        }

        if(curNode->left != nullptr) {
            depth ++;
            traversial(curNode->left, depth);
            depth --;
        }
        if(curNode->right != nullptr) {
            depth ++;
            traversial(curNode->right, depth);
            depth --;
        }
    }

public:
    // // 1. 迭代法实现
    // int findBottomLeftValue(TreeNode *root) {
    //     if((root->left == nullptr) && (root->right == nullptr)) return root->val;
    //     queue<TreeNode*> que;
    //     int result;

    //     que.push(root);
    //     while(!que.empty()) {
    //         size_t sizeQue = que.size();
    //         for(size_t i = 0; i < sizeQue; i++) {
    //             TreeNode *curNode = que.front();
    //             que.pop();

    //             if(i == 0) result = curNode->val;
    //             if(curNode->left != nullptr) que.push(curNode->left);
    //             if(curNode->right != nullptr) que.push(curNode->right);
    //         }
    //     }
    //     return result;
    // }

    // 2.递归法实现
    int findBottomLeftValue(TreeNode *root) {
        if(root == nullptr) return 0;
        traversial(root, 0);
        return findNode->val;
    }
};

// Helper function to build a binary tree
TreeNode* buildTree(const vector<int>& nodes, int nullVal = -1) {
    if (nodes.empty()) return nullptr;
    vector<TreeNode*> treeNodes;
    for (int val : nodes) {
        treeNodes.push_back(val == nullVal ? nullptr : new TreeNode(val));
    }
    int pos = 1;
    for (size_t i = 0; i < treeNodes.size(); ++i) {
        if (treeNodes[i]) {
            if (pos < treeNodes.size()) treeNodes[i]->left = treeNodes[pos++];
            if (pos < treeNodes.size()) treeNodes[i]->right = treeNodes[pos++];
        }
    }
    return treeNodes[0];
}

int main() {
    Solution sol;

    // Test 1: [2,1,3]
    TreeNode* root1 = buildTree({2,1,3});
    int res1 = sol.findBottomLeftValue(root1);
    cout << "Test 1: " << res1 << " (Expected: 1)" << endl;

    // Test 2: [1,2,3,4,null,5,6,null,null,7]
    TreeNode* root2 = buildTree({1,2,3,4,-1,5,6,-1,-1,7});
    int res2 = sol.findBottomLeftValue(root2);
    cout << "Test 2: " << res2 << " (Expected: 7)" << endl;

    // Test 3: [1]
    TreeNode* root3 = buildTree({1});
    int res3 = sol.findBottomLeftValue(root3);
    cout << "Test 3: " << res3 << " (Expected: 1)" << endl;

    // Test 4: [1,2,null,3,null,4,null,5]
    TreeNode* root4 = buildTree({1,2,-1,3,-1,4,-1,5});
    int res4 = sol.findBottomLeftValue(root4);
    cout << "Test 4: " << res4 << " (Expected: 5)" << endl;

    // Test 5: [1,2,3,4,5,6,7]
    TreeNode* root5 = buildTree({1,2,3,4,5,6,7});
    int res5 = sol.findBottomLeftValue(root5);
    cout << "Test 5: " << res5 << " (Expected: 4)" << endl;    
}