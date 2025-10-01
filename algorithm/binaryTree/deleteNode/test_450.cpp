#include <iostream>
#include <vector>
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
    int deleteVal;

    TreeNode *findMinNode(TreeNode *curNode) {
        while(curNode != nullptr && curNode->left != nullptr) curNode = curNode->left;
        return curNode;
    }
    
    TreeNode *traversal(TreeNode *curNode) {
        if(curNode == nullptr) return nullptr;

        if(deleteVal == curNode->val) {
            // 叶子节点处理
            if(curNode->left == nullptr && curNode->right == nullptr) {
                delete curNode;
                return nullptr;
            } else {
                // 双边节点处理：寻找该节点右子树最小值来替代该节点（或左子树最大值来替代该节点）
                if(curNode->left != nullptr && curNode->right != nullptr) {
                    TreeNode *minNode = findMinNode(curNode->right);
                    deleteVal = minNode->val;    
                    curNode->val = minNode->val;
                    curNode->right = traversal(curNode->right);
                    return curNode;
                } 
                else if(curNode->left != nullptr) {     // 左单边节点处理
                    TreeNode *temp = curNode->left;
                    delete curNode;
                    return temp;
                } 
                else {
                    TreeNode *temp = curNode->right;    // 右单边节点处理
                    delete curNode;
                    return temp;
                }
            }
        }
        
        // TreeNode *返回类型 -> 重构二叉树
        if(deleteVal < curNode->val) curNode->left = traversal(curNode->left);
        else curNode->right = traversal(curNode->right);

        return curNode;
    }

public:
    TreeNode *deleteNode(TreeNode *root, int key) {
        if(root == nullptr) return nullptr;
        deleteVal = key;
        return traversal(root);
    }
};

// helpers for tests
TreeNode* insertBST(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (val < root->val) root->left = insertBST(root->left, val);
    else if (val > root->val) root->right = insertBST(root->right, val);
    // ignore duplicates for these tests
    return root;
}

vector<int> inorder(TreeNode* root) {
    vector<int> res;
    if (!root) return res;
    vector<TreeNode*> stack;
    TreeNode* cur = root;
    while (cur || !stack.empty()) {
        while (cur) { stack.push_back(cur); cur = cur->left; }
        cur = stack.back(); stack.pop_back();
        res.push_back(cur->val);
        cur = cur->right;
    }
    return res;
}

string vecToStr(const vector<int>& v) {
    string s = "[";
    for (size_t i = 0; i < v.size(); ++i) {
        if (i) s += ", ";
        s += to_string(v[i]);
    }
    s += "]";
    return s;
}

void runTest(const string& name, vector<int> values, int delKey, const vector<int>& expected) {
    TreeNode* root = nullptr;
    for (int v : values) root = insertBST(root, v);
    Solution sol;
    TreeNode* out = sol.deleteNode(root, delKey);
    vector<int> res = inorder(out);
    cout << name << " - Result: " << vecToStr(res) << " Expected: " << vecToStr(expected) << "\n";
}

// main with multiple tests
int main() {
    // base tree used in several tests: [5,3,6,2,4,7] (LeetCode example)
    vector<int> base = {5,3,6,2,4,7};

    // Test 1: delete a node with two children (3)
    runTest("Test1 delete 3", base, 3, {2,4,5,6,7});

    // Test 2: delete the root (5)
    runTest("Test2 delete 5", base, 5, {2,3,4,6,7});

    // Test 3: delete non-existent key (8) -> tree unchanged
    runTest("Test3 delete 8", base, 8, {2,3,4,5,6,7});

    // Test 4: single node tree delete root
    runTest("Test4 single node delete 1", {1}, 1, {});

    // Test 5: root with only left child
    runTest("Test5 root with left child delete 2", {2,1}, 2, {1});

    // Test 6: root with only right child
    runTest("Test6 root with right child delete 2", {2,3}, 2, {3});

    // Test 7: delete leaf (7)
    runTest("Test7 delete leaf 7", base, 7, {2,3,4,5,6});

    return 0;
}
