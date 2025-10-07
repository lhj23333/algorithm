#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class Solution {
private:
    int direction[4][2] = {
        {1, 0},
        {0, 1},
        {0, -1},
        {-1, 0}
    };

    void bfs(const vector<vector<int>> &mountain, vector<vector<bool>> &border, int x, int y) {
        if(border[y][x]) return;
        border[y][x] = true;

        for(int i = 0; i < 4; i ++) {
            int nextX = x + direction[i][0];
            int nextY = y + direction[i][1];
            if(nextX < 0 || nextX >= mountain[0].size() || nextY < 0 || nextY >= mountain.size()) continue;
            if(mountain[nextY][nextX] >= mountain[y][x]) {
                bfs(mountain, border, nextX, nextY);
            }
        }   
    }

    void dfs(const vector<vector<int>> &mountain, vector<vector<bool>> &border, deque<pair<int, int>> &dq) {
        while (!dq.empty()) {
            auto [curX, curY] = dq.front();
            dq.pop_front();

            for(int i = 0; i < 4; i ++) {
                int nextX = curX + direction[i][0];
                int nextY = curY + direction[i][1];
                if(nextX < 0 || nextX >= mountain[0].size() || nextY < 0 || nextY >= mountain.size() || border[nextY][nextX]) continue;
                if(mountain[nextY][nextX] >= mountain[curY][curX]) {
                    border[nextY][nextX] = true;
                    dq.push_back({nextX, nextY});
                }
            }   
        }
    }

    void printfWater(const vector<vector<bool>> &firstBorder, const vector<vector<bool>> &secondBorder) {
        for(int i = 0; i < firstBorder.size(); i ++) {
            for(int j = 0; j < firstBorder[i].size(); j ++) {
                if(firstBorder[i][j] && secondBorder[i][j]) cout << i << " " << j << endl;
            }
        }
    };

public:
    void mountainAndWater(const vector<vector<int>> &mountain) {
        // deque<pair<int, int>> dq;
        
        vector<vector<bool>> firstBorder(mountain.size(), vector<bool>(mountain[0].size(), false));
        vector<vector<bool>> secondBorder(mountain.size(), vector<bool>(mountain[0].size(), false));

        for(int i = 0 ; i < mountain.size(); i ++) {
            // firstBorder[i][0] = true;
            // dq.push_back({0, i});
            // dfs(mountain, firstBorder, dq);
            bfs(mountain, firstBorder, 0, i);

            // secondBorder[i][mountain[0].size() - 1] = true;
            // dq.push_back({mountain[0].size() - 1, i});
            // dfs(mountain, secondBorder, dq);
            bfs(mountain, secondBorder, mountain[0].size() - 1, i);
        }

        for(int i = 0 ; i < mountain[0].size(); i ++) {
            // firstBorder[0][i] = true;
            // dq.push_back({i, 0});
            // dfs(mountain, firstBorder, dq);
            bfs(mountain, firstBorder, i, 0);

            // secondBorder[mountain.size() - 1][i] = true;
            // dq.push_back({i, mountain.size() - 1});
            // dfs(mountain, secondBorder, dq);
            bfs(mountain, secondBorder, i, mountain.size() - 1);
        }

        printfWater(firstBorder, secondBorder);
    }
};

int main() {
    Solution sol;

    int n, m;
    cin >> n >> m;

    vector<vector<int>> mountain(n, vector<int>(m));
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) {
            cin >> mountain[i][j];
        }
    }

    sol.mountainAndWater(mountain);
    return 0;
}