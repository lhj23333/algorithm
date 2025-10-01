#include <iostream>
#include <vector>

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
    TreeNode *traversal(vector<int> &inorder, vector<int> &postorder) {
        if(postorder.empty()) return NULL;

        int rootValue = postorder[postorder.size() - 1];
        TreeNode* root = new TreeNode(rootValue);

        if (postorder.size() == 1) return root;
        
        size_t findRootIndex;
        for(size_t i = 0; i < inorder.size(); i ++) {
            if(inorder[i] == rootValue) {
                findRootIndex = i;
                break;
            }
        }

        // 切割中序
        vector<int> leftInorder(inorder.begin(), inorder.begin() + findRootIndex);
        vector<int> rightInorder(inorder.begin() + findRootIndex + 1, inorder.end());

        postorder.resize(postorder.size() - 1);

        // 切割后序
        vector<int> leftPostorder(postorder.begin(), postorder.begin() + leftInorder.size());
        vector<int> rightPostorder(postorder.begin() + leftPostorder.size(), postorder.end());

        root->left = traversal(leftInorder, leftPostorder);
        root->right =  traversal(rightInorder, rightPostorder);

        return root;
    }

public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if(inorder.empty() || postorder.empty()) return {};
        return traversal(inorder, postorder);
    }
};

// 辅助函数：层序遍历打印二叉树
void printTree(TreeNode* root) {
    if (!root) {
        cout << "[]";
        return;
    }
    vector<TreeNode*> q{root};
    vector<string> res;
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.erase(q.begin());
        if (node) {
            res.push_back(to_string(node->val));
            q.push_back(node->left);
            q.push_back(node->right);
        } else {
            res.push_back("null");
        }
    }
    // 去除末尾多余的 null
    while (!res.empty() && res.back() == "null") res.pop_back();
    cout << "[";
    for (size_t i = 0; i < res.size(); ++i) {
        cout << res[i];
        if (i != res.size() - 1) cout << ",";
    }
    cout << "]";
}

int main() {
    // 测试用例1
    vector<int> inorder1 = {9,3,15,20,7};
    vector<int> postorder1 = {9,15,7,20,3};
    TreeNode* tree1 = Solution().buildTree(inorder1, postorder1);
    cout << "Test 1: ";
    printTree(tree1);
    cout << " | Expected: [3,9,20,null,null,15,7]" << endl;

    // 测试用例2：空树
    vector<int> inorder2 = {};
    vector<int> postorder2 = {};
    TreeNode* tree2 = Solution().buildTree(inorder2, postorder2);
    cout << "Test 2: ";
    printTree(tree2);
    cout << " | Expected: []" << endl;

    // 测试用例3：只有一个节点
    vector<int> inorder3 = {1};
    vector<int> postorder3 = {1};
    TreeNode* tree3 = Solution().buildTree(inorder3, postorder3);
    cout << "Test 3: ";
    printTree(tree3);
    cout << " | Expected: [1]" << endl;

    // 测试用例4：左子树只有一个节点
    vector<int> inorder4 = {2,1};
    vector<int> postorder4 = {2,1};
    TreeNode* tree4 = Solution().buildTree(inorder4, postorder4);
    cout << "Test 4: ";
    printTree(tree4);
    cout << " | Expected: [1,2]" << endl;

    // 测试用例5：右子树只有一个节点
    vector<int> inorder5 = {1,2};
    vector<int> postorder5 = {2,1};
    TreeNode* tree5 = Solution().buildTree(inorder5, postorder5);
    cout << "Test 5: ";
    printTree(tree5);
    cout << " | Expected: [1,null,2]" << endl;
}