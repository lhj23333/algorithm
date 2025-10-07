#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class Solution {
private:
    int diration[4][2] = {
        {1, 0},
        {0, 1},
        {0, -1},
        {-1, 0}
    };

    void dfs(vector<vector<int>> &grid, int x, int y) {
        grid[y][x] = 2;
        for(int i = 0; i < 4; i ++) {
            int nextX = x + diration[i][0];
            int nextY = y + diration[i][1];
            if(nextX < 0 || nextX >= grid[0].size() || nextY < 0 || nextY >= grid.size()) continue;
            if(grid[nextY][nextX] == 1) {
                dfs(grid, nextX, nextY);
            } 
        }
    }

    void bfs(vector<vector<int>> &grid, deque<pair<int, int>> &dq) {
        while (!dq.empty()){
            auto [curX, curY] = dq.front();
            dq.pop_front();
            for(int i = 0; i < 4; i ++) {
                int nextX = curX + diration[i][0];
                int nextY = curY + diration[i][1];
                if(nextX < 0 || nextX >= grid[0].size() || nextY < 0 || nextY >= grid.size()) continue;
                if(grid[nextY][nextX] == 1) {
                    grid[nextY][nextX] = 2;
                    dq.push_back({nextX, nextY});
                } 
            }
        }    
    }

    void printfGrid(vector<vector<int>> &grid) {
        for(int i = 0; i < grid.size(); i ++) {
            for(int j = 0; j < grid[i].size() - 1; j ++) {
                if(grid[i][j] == 2) cout << 1 << " ";
                else cout << 0 << " ";
            }
            if(grid[i][grid[i].size() - 1] == 2) cout << 1 << endl;
            else cout << 0 << endl;
        }
    }

public:
    void sunkIsland(vector<vector<int>> &grid) {
        // deque<pair<int, int>> dq;
        for(int i = 0; i < grid.size(); i ++) {
            if(grid[i][0] == 1) {
                // grid[i][0] = 2;
                // dq.push_back({0, i});
                // bfs(grid, dq);
                dfs(grid, 0, i);
            }
            if(grid[i][grid[i].size() - 1] == 1) {
                // grid[i][grid[i].size() - 1] = 2;
                // dq.push_back({grid[i].size() - 1, i});
                // bfs(grid, dq);
                dfs(grid, grid[i].size() - 1, i);
            }
        }

        for(int i = 0; i < grid[0].size(); i ++) {
            if(grid[0][i] == 1) {
                // grid[0][i] = 2;
                // dq.push_back({i, 0});
                // bfs(grid, dq);
                dfs(grid, i, 0);
            }
            if(grid[grid.size() - 1][i] == 1) {
                // grid[grid.size() - 1][i] = 2;
                // dq.push_back({i, grid.size() - 1});
                // bfs(grid, dq);
                dfs(grid, i, grid.size() - 1);
            }
        }
        printfGrid(grid);
    }  
};

int main() {
    Solution sol;
    
    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) {
            cin >> grid[i][j];
        }
    }

    sol.sunkIsland(grid);
    return 0;
}