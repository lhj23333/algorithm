#include <iostream>
#include <string>
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
    // // 传参 path 不进行"&"取地址时，传入的都是新的对象，无需进行回溯
    // void traversal(TreeNode *curNode, vector<int> path, vector<string> &result) {
    //     path.push_back(curNode->val);
    //     if((curNode->left == nullptr) && (curNode->right == nullptr)) {
    //         string pathStr = to_string(path[0]);
    //         for(size_t i = 1; i < path.size(); i++) {
    //             pathStr += "->" + to_string(path[i]);
    //         }
    //         result.push_back(pathStr);
    //         return ;
    //     }

    //     if(curNode->left != nullptr) traversal(curNode->left, path, result);
    //     if(curNode->right != nullptr) traversal(curNode->right, path, result);
    // }

    // 传参 path 进行"&"取地址时，传入为同一对象，需进行回溯
    void traversal(TreeNode *curNode, vector<int> &path, vector<string> &result) {
        path.push_back(curNode->val);
        if((curNode->left == nullptr) && (curNode->right == nullptr)) {
            string pathStr = to_string(path[0]);
            for(size_t i = 1; i < path.size(); i++) {
                pathStr += "->" + to_string(path[i]);
            }
            result.push_back(pathStr);
            path.pop_back();    // 回溯
            return ;
        }

        if(curNode->left != nullptr) traversal(curNode->left, path, result);
        if(curNode->right != nullptr) traversal(curNode->right, path, result);
        path.pop_back();    // 回溯
    }
    
public:
    vector<string> binaryTreePaths(TreeNode *root) {
        if(root == nullptr) return {};
        vector<string> result;
        vector<int> path;
        traversal(root, path, result);
        return result;
    }
};

int main()
{
    // 构造测试用例1：空树
    Solution sol;
    TreeNode* root1 = nullptr;
    auto res1 = sol.binaryTreePaths(root1);
    cout << "Test 1 (空树): 正确结果: [] 实际结果: [";
    for (size_t i = 0; i < res1.size(); ++i) {
        cout << res1[i];
        if (i != res1.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    // 构造测试用例2：只有一个节点
    TreeNode* root2 = new TreeNode(1);
    auto res2 = sol.binaryTreePaths(root2);
    cout << "Test 2 (单节点): 正确结果: [\"1\"] 实际结果: [";
    for (size_t i = 0; i < res2.size(); ++i) {
        cout << res2[i];
        if (i != res2.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    // 构造测试用例3：左子树
    TreeNode* root3 = new TreeNode(1, new TreeNode(2, new TreeNode(5), nullptr), nullptr);
    auto res3 = sol.binaryTreePaths(root3);
    cout << "Test 3 (左子树): 正确结果: [\"1->2->5\"] 实际结果: [";
    for (size_t i = 0; i < res3.size(); ++i) {
        cout << res3[i];
        if (i != res3.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    // 构造测试用例4：左右子树
    TreeNode* root4 = new TreeNode(1,
        new TreeNode(2, nullptr, new TreeNode(5)),
        new TreeNode(3)
    );
    auto res4 = sol.binaryTreePaths(root4);
    cout << "Test 4 (左右子树): 正确结果: [\"1->2->5\", \"1->3\"] 实际结果: [";
    for (size_t i = 0; i < res4.size(); ++i) {
        cout << res4[i];
        if (i != res4.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    // 构造测试用例5：更复杂的树
    TreeNode* root5 = new TreeNode(1,
        new TreeNode(2, new TreeNode(4), new TreeNode(5)),
        new TreeNode(3, nullptr, new TreeNode(6))
    );
    auto res5 = sol.binaryTreePaths(root5);
    cout << "Test 5 (复杂树): 正确结果: [\"1->2->4\", \"1->2->5\", \"1->3->6\"] 实际结果: [";
    for (size_t i = 0; i < res5.size(); ++i) {
        cout << res5[i];
        if (i != res5.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
}
