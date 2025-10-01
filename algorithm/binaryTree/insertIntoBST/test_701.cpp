#include <iostream>
#include <vector>
#include <queue>
#include <string>
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
    int insertVal;

    // 算法思路：搜索二叉树插入元素节点
    //          不要求最终是一棵平衡树 -> 可在叶子节点处进行搜索添加插入
    void traversal(TreeNode *curNode) {
        if(curNode == nullptr) return ;

        if(insertVal < curNode->val) {
            if(curNode->left == nullptr) {
                curNode->left = new TreeNode(insertVal);
                return;
            }
            traversal(curNode->left);
        }
        if(insertVal > curNode->val) {
            if(curNode->right == nullptr) {
                curNode->right = new TreeNode(insertVal);
                return ;
            }
            traversal(curNode->right);
        }
    }

public:
    TreeNode *insertIntoBST(TreeNode *root, int val) {
        if(root == nullptr) return new TreeNode(val);
        insertVal = val;
        traversal(root);
        return root;
    }
};

// build tree from level-order vector, using INT_MIN as null marker
TreeNode* buildTreeFromLevel(const vector<int>& vals) {
    if(vals.empty()) return nullptr;
    vector<TreeNode*> nodes(vals.size(), nullptr);
    for(size_t i = 0; i < vals.size(); ++i) {
        if(vals[i] != INT_MIN) nodes[i] = new TreeNode(vals[i]);
    }
    for(size_t i = 0; i < vals.size(); ++i) {
        if(nodes[i]) {
            size_t l = 2*i + 1;
            size_t r = 2*i + 2;
            if(l < vals.size()) nodes[i]->left = nodes[l];
            if(r < vals.size()) nodes[i]->right = nodes[r];
        }
    }
    return nodes[0];
}

// serialize tree to level-order string, trimming trailing nulls
string serialize(TreeNode* root) {
    if(!root) return "[]";
    queue<TreeNode*> q;
    q.push(root);
    vector<string> out;
    while(!q.empty()) {
        TreeNode* n = q.front(); q.pop();
        if(n) {
            out.push_back(to_string(n->val));
            q.push(n->left);
            q.push(n->right);
        } else {
            out.push_back("null");
        }
    }
    // trim trailing "null"
    while(!out.empty() && out.back() == "null") out.pop_back();
    string s = "[";
    for(size_t i = 0; i < out.size(); ++i) {
        if(i) s += ",";
        s += out[i];
    }
    s += "]";
    return s;
}

int main()
{
    Solution sol;

    // Test 1: insert into non-empty BST
    {
        TreeNode* root = buildTreeFromLevel({4,2,7,1,3});
        TreeNode* res = sol.insertIntoBST(root, 5);
        string got = serialize(res);
        TreeNode* expRoot = buildTreeFromLevel({4,2,7,1,3,5});
        string expected = serialize(expRoot);
        cout << got << " " << expected << "\n";
    }

    // Test 2: insert into empty tree
    {
        TreeNode* root = nullptr;
        TreeNode* res = sol.insertIntoBST(root, 5);
        string got = serialize(res);
        TreeNode* expRoot = buildTreeFromLevel({5});
        string expected = serialize(expRoot);
        cout << got << " " << expected << "\n";
    }

    // Test 3: insert value that becomes left child deeper in tree
    {
        TreeNode* root = buildTreeFromLevel({40,20,60,10,30,50,70});
        TreeNode* res = sol.insertIntoBST(root, 25);
        string got = serialize(res);
        TreeNode* expRoot = buildTreeFromLevel({40,20,60,10,30,50,70,INT_MIN,INT_MIN,25});
        string expected = serialize(expRoot);
        cout << got << " " << expected << "\n";
    }

    // Test 4: insert duplicate value (no insertion expected per implementation)
    {
        TreeNode* root = buildTreeFromLevel({40,20,60,10,30,50,70});
        TreeNode* res = sol.insertIntoBST(root, 20); // duplicate
        string got = serialize(res);
        TreeNode* expRoot = buildTreeFromLevel({40,20,60,10,30,50,70});
        string expected = serialize(expRoot);
        cout << got << " " << expected << "\n";
    }

    return 0;
}
