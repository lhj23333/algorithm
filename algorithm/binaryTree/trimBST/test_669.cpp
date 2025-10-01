#include <iostream>
#include <vector>
#include <queue>
#include <limits>

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
    TreeNode *traversal(TreeNode *curNode, int low, int high){
        if(curNode == nullptr) return nullptr;
    
        if(curNode->val < low) {
            if(curNode->right != nullptr) return traversal(curNode->right, low, high);
            else return nullptr;

            delete curNode;
        }
        if(curNode->val > high) {
            if(curNode->left != nullptr) return traversal(curNode->left, low, high);
            else return nullptr;
            
            delete curNode;
        }

        curNode->left = traversal(curNode->left, low, high);
        curNode->right = traversal(curNode->right, low, high);

        return curNode;
    }

public:
    TreeNode *trimBST(TreeNode *root, int low, int high) {
        if(root == nullptr) return nullptr;
        return traversal(root, low, high);
    }
};

// Build tree from level-order vector, using sentinel (here INT_MIN) for nulls
TreeNode* buildFromLevel(const vector<int>& vals, int nullSentinel = numeric_limits<int>::min()) {
    if(vals.empty()) return nullptr;
    if(vals[0] == nullSentinel) return nullptr;
    TreeNode* root = new TreeNode(vals[0]);
    queue<TreeNode*> q;
    q.push(root);
    size_t i = 1;
    while(!q.empty() && i < vals.size()) {
        TreeNode* node = q.front(); q.pop();
        if(i < vals.size()) {
            if(vals[i] != nullSentinel) {
                node->left = new TreeNode(vals[i]);
                q.push(node->left);
            }
            ++i;
        }
        if(i < vals.size()) {
            if(vals[i] != nullSentinel) {
                node->right = new TreeNode(vals[i]);
                q.push(node->right);
            }
            ++i;
        }
    }
    return root;
}

void deleteTree(TreeNode* root) {
    if(!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

void inorderCollect(TreeNode* root, vector<int>& out) {
    if(!root) return;
    inorderCollect(root->left, out);
    out.push_back(root->val);
    inorderCollect(root->right, out);
}

string vecToString(const vector<int>& v) {
    string s = "[";
    for(size_t i=0;i<v.size();++i){
        if(i) s += ",";
        s += to_string(v[i]);
    }
    s += "]";
    return s;
}

int main() {
    Solution sol;
    const int nil = numeric_limits<int>::min();

    struct Test { vector<int> tree; int low; int high; vector<int> expectedInorder; string name; };

    vector<Test> tests = {
        // LeetCode example 1: [1,0,2], low=1,high=2 => [1,2]
        {{1,0,2}, 1, 2, {1,2}, "Example1"},
        // LeetCode example 2: [3,0,4,null,2,null,null,1], low=1,high=3 => [1,2,3]
        {{3,0,4,nil,2,nil,nil,1}, 1, 3, {1,2,3}, "Example2"},
        // empty tree
        {{}, 0, 1, {}, "EmptyTree"},
        // all nodes less than low => empty
        {{1,0,nil}, 2, 3, {}, "AllBelowLow"},
        // all nodes within range => unchanged inorder
        {{2,1,3}, 1, 3, {1,2,3}, "AllWithinRange"},
        // single node out of range
        {{0}, 1, 2, {}, "SingleOutOfRange"},
    };

    for(size_t i=0;i<tests.size();++i){
        auto &t = tests[i];
        TreeNode* root = buildFromLevel(t.tree, nil);
        TreeNode* trimmed = sol.trimBST(root, t.low, t.high);
        vector<int> got;
        inorderCollect(trimmed, got);

        cout << "Test " << i+1 << " (" << t.name << ") Result: " << vecToString(got) << " Expected: " << vecToString(t.expectedInorder) << "\n";

        // cleanup
        deleteTree(trimmed);
    }

    return 0;
}