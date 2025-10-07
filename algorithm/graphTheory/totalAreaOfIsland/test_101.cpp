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
    int totalArea;

    int bfs(vector<vector<int>> &grid, vector<vector<bool>> &visited, deque<pair<int, int>> &dq) {
        int area = 1;
        bool isIsland = true;
        while(!dq.empty()) {
            auto [curX, curY] = dq.front();
            dq.pop_front();

            for(int i = 0; i < 4; i ++) {
                int nextX = curX + diration[i][0];
                int nextY = curY + diration[i][1];
                if(nextX < 0 || nextY < 0 || nextX >= grid[0].size() || nextY >= grid.size()) {
                    if(isIsland) isIsland = false;
                    continue;
                }
                if(!visited[nextY][nextX] && grid[nextY][nextX]) {
                    visited[nextY][nextX] = true;
                    area ++;
                    dq.push_back({nextX, nextY});
                }
            }
        }
        if(isIsland) return area;
        else return 0;
    }

public:
    int totalAreaOfIsland(vector<vector<int>> &grid, vector<vector<bool>> &visited) {
        totalArea = 0;

        for(int i = 0; i < grid.size(); i ++) {
            for(int j = 0 ; j < grid[i].size(); j ++) {
                if(visited[i][j] || !grid[i][j]) continue;
                visited[i][j] = true;
                deque<pair<int, int>> dq;
                dq.push_back({j, i});
                totalArea += bfs(grid, visited, dq);
            }
        }
        return totalArea;
    }
};

int main() 
{
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
    cout << sol.totalAreaOfIsland(grid, visited);
    return 0;
}