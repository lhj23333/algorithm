#include <iostream>
#include <climits>

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
    
    TreeNode *traversal(TreeNode *curNode) {
        if(curNode == nullptr) return nullptr;

        if(curNode->val > p_node->val) return traversal(curNode->left);
        if(curNode->val < q_node->val) return traversal(curNode->right);

        return curNode;
    }

public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        if(root == nullptr || p == nullptr || q == nullptr) return nullptr;
        p_node = p->val > q->val ? p : q;
        q_node = p->val < q->val ? p : q;
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

int main() {
    Solution sol;

    // Test 1: Full BST example
    TreeNode* n6 = new TreeNode(6);
    TreeNode* n2 = new TreeNode(2);
    TreeNode* n8 = new TreeNode(8);
    TreeNode* n0 = new TreeNode(0);
    TreeNode* n4 = new TreeNode(4);
    TreeNode* n7 = new TreeNode(7);
    TreeNode* n9 = new TreeNode(9);
    TreeNode* n3 = new TreeNode(3);
    TreeNode* n5 = new TreeNode(5);
    n6->left = n2; n6->right = n8;
    n2->left = n0; n2->right = n4;
    n8->left = n7; n8->right = n9;
    n4->left = n3; n4->right = n5;
    // LCA of 2 and 8 is 6
    printResult(1, sol.lowestCommonAncestor(n6, n2, n8), 6);

    // Test 2: LCA where one node is ancestor of the other (2 and 4 -> 2)
    printResult(2, sol.lowestCommonAncestor(n6, n2, n4), 2);

    // Test 3: Single node tree, p == q == root
    TreeNode* r1 = new TreeNode(1);
    printResult(3, sol.lowestCommonAncestor(r1, r1, r1), 1);

    // Test 4: Left skewed tree 3->2->1, LCA(1,2) = 2
    TreeNode* a3 = new TreeNode(3);
    TreeNode* a2 = new TreeNode(2);
    TreeNode* a1 = new TreeNode(1);
    a3->left = a2; a2->left = a1;
    printResult(4, sol.lowestCommonAncestor(a3, a1, a2), 2);

    // Test 5: Right skewed tree 1->2->3, LCA(1,3) = 1
    TreeNode* b1 = new TreeNode(1);
    TreeNode* b2 = new TreeNode(2);
    TreeNode* b3 = new TreeNode(3);
    b1->right = b2; b2->right = b3;
    printResult(5, sol.lowestCommonAncestor(b1, b1, b3), 1);

    // Test 6: Null root -> expect null
    printResult(6, sol.lowestCommonAncestor(nullptr, n2, n8), INT_MIN);

    // Test 7: One of the targets is null -> expect null
    printResult(7, sol.lowestCommonAncestor(n6, n2, nullptr), INT_MIN);

    return 0;
}
