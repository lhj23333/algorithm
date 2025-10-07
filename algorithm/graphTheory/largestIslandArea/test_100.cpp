#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class Solution {
private:
    int largestArea;
    int Area;
    int diration[4][2] = {
        {1, 0},
        {0, 1},
        {-1, 0},
        {0, -1}
    };

    int bfs(vector<vector<int>> &grid, vector<vector<bool>> &visited, deque<pair<int, int>> &dq) {
        int area = 1;
        while(!dq.empty()) {
            auto [curX, curY] = dq.front();
            dq.pop_front();
            for(int i = 0; i < 4; i ++){
                int nextX = dq.front().first + diration[i][0];
                int nextY = dq.front().second + diration[i][1];
                if(nextX < 0 || nextY < 0 || nextX >= grid[0].size() || nextY >= grid.size()) continue;
                if(!visited[nextY][nextX] && grid[nextY][nextX]) {
                    area ++;
                    visited[nextY][nextX] = true;
                    dq.push_back({nextX, nextY});
                }
            }
        }
        return area;
    }

    void dfs(vector<vector<int>> &grid, vector<vector<bool>> &visited, int x, int y) {
        for(int i = 0; i < 4; i ++) {
            int nextX = x + diration[i][0];
            int nextY = y + diration[i][1];
            if(nextX < 0 || nextY < 0 || nextX >= grid[0].size() || nextY >= grid.size()) continue;
            if(!visited[nextY][nextX] && grid[nextY][nextX]) {
                visited[nextY][nextX] = true;
                Area ++;
                dfs(grid, visited, nextX, nextY);
            }
        }
    }

public:
    int largestIslandArea(vector<vector<int>> &grid, vector<vector<bool>> &visited) {
        largestArea = 0;
        for(int i = 0; i < grid.size(); i ++) {
            for(int j = 0; j < grid[i].size(); j ++) {
                if(visited[i][j] || !grid[i][j]) continue;
                else {
                    visited[i][j] = true;
                    deque<pair<int, int>> dq;
                    dq.push_back({j, i});
                    largestArea = max(largestArea, bfs(grid, visited, dq));

                    // Area = 1;
                    // dfs(grid, visited, j, i);
                    // largestArea = max(largestArea, Area);
                }
            }
        }
        return largestArea;
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
    
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    cout << sol.largestIslandArea(grid, visited) << endl;

    return 0;
}