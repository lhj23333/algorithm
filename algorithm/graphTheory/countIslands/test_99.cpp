#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class Solution {
private:
    int islanNums;
    int dir[4][2] = {
        {0, 1},
        {1, 0},
        {-1, 0},
        {0, -1}
    };

    void dfs(vector<vector<int>> &grid, vector<vector<bool>> &visited, int x, int y) {
        for(int i = 0; i < 4; i ++) {
            int nextX = x + dir[i][0];
            int nextY = y + dir[i][1];
            if(nextX < 0 || nextX >= grid[0].size() || nextY < 0 || nextY >= grid.size()) continue;
            if(!visited[nextY][nextX] && grid[nextY][nextX]) {
                visited[nextY][nextX] = true;
                dfs(grid, visited, nextX, nextY);
            } 
        }
    }

    void bfs(vector<vector<int>> &grid, vector<vector<bool>> &visited, deque<pair<int, int>> &que) {        
        while(!que.empty()) {
            for(int i = 0; i < 4; i ++) {
                int nextX = que.front().first + dir[i][0];
                int nextY = que.front().second + dir[i][1];                
                if(nextX < 0 || nextX >= grid[0].size() || nextY < 0 || nextY >= grid.size()) continue;
                if(!visited[nextY][nextX] && grid[nextY][nextX]) {
                    visited[nextY][nextX] = true;
                    que.push_back({nextX, nextY});
                }
            }
            que.pop_front();
        }
    }

public:
    int CountIslans(vector<vector<int>> &grid, vector<vector<bool>> &visited){
        islanNums = 0;

        for(int i = 0; i < grid.size(); i ++) {
            for(int j = 0; j < grid[i].size(); j++) {
                if(visited[i][j] || !grid[i][j]) continue;
                visited[i][j] = true;
                islanNums ++;
                // dfs(grid, visited, j, i);
                deque<pair<int, int>> que;
                que.push_back({j, i});
                bfs(grid, visited, que);
            }
        }
        return islanNums;
    }
};

int main() {
    Solution sol;

    int n, m;
    cin >> n >> m;

    vector<vector<bool>> visited(n, vector<bool>(m, false)); 
    vector<vector<int>> grid(n, vector<int>(m, 0));
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) {
            cin >> grid[i][j];
        }
    }
    cout << sol.CountIslans(grid, visited) << endl;

    return 0;
}