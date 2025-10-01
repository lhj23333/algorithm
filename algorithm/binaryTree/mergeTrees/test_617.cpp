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
    TreeNode *traversal(TreeNode* root1, TreeNode *root2) {
        if((root1 == nullptr) && (root2 == nullptr)) return nullptr;

        int rootValue;
        if(root1 == nullptr) rootValue = root2->val;
        else if(root2 == nullptr) rootValue = root1->val;
        else rootValue = root1->val + root2->val;
        TreeNode *root = new TreeNode(rootValue);

        root->left = traversal(root1 == nullptr ? nullptr : root1->left, root2 == nullptr ? nullptr : root2->left);
        root->right = traversal(root1 == nullptr ? nullptr : root1->right, root2 == nullptr ? nullptr : root2->right);

        return root;
    } 

public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if((root1 == nullptr) && (root2 == nullptr)) return {};
        if(root1 == nullptr) return root2;
        if(root2 == nullptr) return root1;

        return traversal(root1, root2);
    }
};

// Helper function to get inorder traversal
vector<int> inorder(TreeNode* root) {
    vector<int> res;
    if (root == nullptr) return res;
    vector<int> left = inorder(root->left);
    res.insert(res.end(), left.begin(), left.end());
    res.push_back(root->val);
    vector<int> right = inorder(root->right);
    res.insert(res.end(), right.begin(), right.end());
    return res;
}

// Helper function to print vector
void printVector(const vector<int>& v) {
    cout << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        cout << v[i];
        if (i < v.size() - 1) cout << ",";
    }
    cout << "]";
}

int main() {
    Solution sol;

    // Test 1: Both trees are null
    TreeNode* root1 = nullptr;
    TreeNode* root2 = nullptr;
    TreeNode* merged = sol.mergeTrees(root1, root2);
    vector<int> result1 = inorder(merged);
    vector<int> expected1 = {};
    cout << "Test 1 - Merged inorder: ";
    printVector(result1);
    cout << " Expected: ";
    printVector(expected1);
    cout << endl;

    // Test 2: root1 is null, root2 has one node
    root2 = new TreeNode(1);
    merged = sol.mergeTrees(nullptr, root2);
    vector<int> result2 = inorder(merged);
    vector<int> expected2 = {1};
    cout << "Test 2 - Merged inorder: ";
    printVector(result2);
    cout << " Expected: ";
    printVector(expected2);
    cout << endl;

    // Test 3: root2 is null, root1 has one node
    root1 = new TreeNode(2);
    merged = sol.mergeTrees(root1, nullptr);
    vector<int> result3 = inorder(merged);
    vector<int> expected3 = {2};
    cout << "Test 3 - Merged inorder: ";
    printVector(result3);
    cout << " Expected: ";
    printVector(expected3);
    cout << endl;

    // Test 4: Both trees have one node
    root1 = new TreeNode(1);
    root2 = new TreeNode(2);
    merged = sol.mergeTrees(root1, root2);
    vector<int> result4 = inorder(merged);
    vector<int> expected4 = {3};
    cout << "Test 4 - Merged inorder: ";
    printVector(result4);
    cout << " Expected: ";
    printVector(expected4);
    cout << endl;

    // Test 5: Simple trees
    // root1: 1
    //       / \
    //      3   2
    // root2: 2
    //       / \
    //      1   3
    root1 = new TreeNode(1, new TreeNode(3), new TreeNode(2));
    root2 = new TreeNode(2, new TreeNode(1), new TreeNode(3));
    merged = sol.mergeTrees(root1, root2);
    vector<int> result5 = inorder(merged);
    vector<int> expected5 = {4, 3, 5};  // inorder: 3+1=4, 1+2=3, 2+3=5
    cout << "Test 5 - Merged inorder: ";
    printVector(result5);
    cout << " Expected: ";
    printVector(expected5);
    cout << endl;

    // Test 6: One tree is larger
    // root1: 1
    //       / \
    //      2   3
    //     /
    //    4
    // root2: 1
    //       / \
    //      2   3
    root1 = new TreeNode(1, new TreeNode(2, new TreeNode(4), nullptr), new TreeNode(3));
    root2 = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    merged = sol.mergeTrees(root1, root2);
    vector<int> result6 = inorder(merged);
    vector<int> expected6 = {4, 4, 2, 6};  // inorder: 4, 2+2=4, 1+1=2, 3+3=6
    cout << "Test 6 - Merged inorder: ";
    printVector(result6);
    cout << " Expected: ";
    printVector(expected6);
    cout << endl;

    // Test 7: Overlapping and non-overlapping
    // root1: 1
    //       / \
    //      2   nullptr
    // root2: 3
    //       / \
    //      nullptr 4
    root1 = new TreeNode(1, new TreeNode(2), nullptr);
    root2 = new TreeNode(3, nullptr, new TreeNode(4));
    merged = sol.mergeTrees(root1, root2);
    vector<int> result7 = inorder(merged);
    vector<int> expected7 = {2, 4, 4};  // inorder: 2, 1+3=4, 4
    cout << "Test 7 - Merged inorder: ";
    printVector(result7);
    cout << " Expected: ";
    printVector(expected7);
    cout << endl;

    return 0;
}
