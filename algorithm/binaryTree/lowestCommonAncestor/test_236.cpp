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
    TreeNode *p_node;
    TreeNode *q_node; 

    // 算法思路：
    //      通过后序 -> 左右中遍历，将节点左右支树搜索结果向上反馈
    //      1. 当搜索到 p, q 节点分别在某节点左右支树中，则向上返回该节点
    //      2. 当 p, q 中某一节点为另一节点公共祖先节点时，由于递归的时序性
    //         仅需单向向上反馈即可处理该情况
    TreeNode *traversal(TreeNode *curNode) {
        if(curNode == nullptr) return nullptr;

        TreeNode *leftNode = traversal(curNode->left);
        TreeNode *rightNode = traversal(curNode->right);

        if(curNode == p_node || curNode == q_node) return curNode;
        if(leftNode != nullptr && rightNode != nullptr) return curNode;
        if(leftNode != nullptr) return leftNode;
        if(rightNode != nullptr) return rightNode;
    
        return nullptr;
    }

public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        if(root == nullptr || p == nullptr || q == nullptr) return {};
        p_node = p;
        q_node = q;

        return traversal(root); 
    }
};

static void printResult(int testId, TreeNode* got, int expectedVal) {
    cout << "Test " << testId << ": got: ";
    if (got) cout << got->val;
    else cout << "null";
    cout << ", expected: ";
    if (expectedVal == INT_MIN) cout << "null";
    else cout << expectedVal;
    cout << endl;
}

int main()
{
    Solution sol;

    // Test 1: classic LeetCode example
    //      3
    //     / \
    //    5   1
    //   / \ / \
    //  6  2 0  8
    //    / \
    //   7   4
    TreeNode *n3 = new TreeNode(3);
    TreeNode *n5 = new TreeNode(5);
    TreeNode *n1 = new TreeNode(1);
    TreeNode *n6 = new TreeNode(6);
    TreeNode *n2 = new TreeNode(2);
    TreeNode *n0 = new TreeNode(0);
    TreeNode *n8 = new TreeNode(8);
    TreeNode *n7 = new TreeNode(7);
    TreeNode *n4 = new TreeNode(4);

    n3->left = n5; n3->right = n1;
    n5->left = n6; n5->right = n2;
    n1->left = n0; n1->right = n8;
    n2->left = n7; n2->right = n4;

    TreeNode *res1 = sol.lowestCommonAncestor(n3, n5, n1);
    printResult(1, res1, 3); // expected 3

    // Test 2: one node is ancestor of the other (p is ancestor)
    TreeNode *res2 = sol.lowestCommonAncestor(n3, n5, n4);
    printResult(2, res2, 5); // expected 5

    // Test 3: LCA lower in the tree
    TreeNode *res3 = sol.lowestCommonAncestor(n3, n7, n4);
    printResult(3, res3, 2); // expected 2

    // Test 4: single-node tree, p == q == root
    TreeNode *s1 = new TreeNode(1);
    TreeNode *res4 = sol.lowestCommonAncestor(s1, s1, s1);
    printResult(4, res4, 1); // expected 1

    // Test 5: chain/tree skewed to the right
    // 1 -> 2 -> 3
    TreeNode *c1 = new TreeNode(1);
    TreeNode *c2 = new TreeNode(2);
    TreeNode *c3 = new TreeNode(3);
    c1->right = c2; c2->right = c3;
    TreeNode *res5 = sol.lowestCommonAncestor(c1, c2, c3);
    printResult(5, res5, 2); // expected 2

    // Test 6: one of the inputs is null -> expected null
    TreeNode *res6 = sol.lowestCommonAncestor(n3, n5, nullptr);
    printResult(6, res6, INT_MIN); // expected null

    // Note: cleanup omitted for brevity

    return 0;
}
