// https://kamacoder.com/problempage.php?pid=1170
#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;

    // // 1. 邻接矩阵
    // void dfs(vector<vector<int>> &graph, int curNode, int n) {
    //     if(curNode == n) {
    //         result.push_back(path);
    //         return;
    //     }

    //     for(int i = 1; i <= n; i++) {
    //         if(graph[curNode][i] == 0) continue;
    //         path.push_back(i);
    //         dfs(graph, i, n);
    //         path.pop_back();
    //     }
    // }

    // 2. 邻接表
    void dfs(const vector<list<int>> &graph, int curNode, int n) {
        if(curNode == n) {
            result.push_back(path);
            return;
        }

        for(int i : graph[curNode]) {
            path.push_back(i);
            dfs(graph, i, n);
            path.pop_back();
        }
    }

    void printfPath() {
        if(result.empty()) {
            cout << - 1 << endl;
            return ;
        }
        for(const vector<int> &pa : result) {
            for(int j = 0; j < pa.size() - 1; j ++) {
                cout << pa[j] << " ";
            }
            cout << pa[pa.size() - 1] << endl;
        }
    }

public:
    // // 1. 邻接矩阵
    // void AccessiblePath(vector<vector<int>> &graph, int n) {
    //     result.clear();
    //     path.clear();
    //     path.push_back(1);
    //     dfs(graph, 1, n);
    //     printfPath();
    // }

    // 2. 邻接表
    void AccessiblePath(vector<list<int>> &graph, int n) {
        result.clear();
        path.clear();
        path.push_back(1);
        dfs(graph, 1, n);
        printfPath();
    }
};

int main() {
    Solution sol;

    int m, n;
    cin >> m >> n;

    // // 邻接矩阵
    // vector<vector<int>> graph(n + 1, vector<int>(n + 1, 0));
    // int s, t;
    // while(m --) {
    //     cin >> s >> t;
    //     graph[s][t] = 1;
    // }

    // 邻接链表
    vector<list<int>> graph(n + 1);
    while(m --) {
        int s, t;
        cin >> s >> t;
        graph[s].push_back(t);
    }
    sol.AccessiblePath(graph, n);

    return 0;
}