#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
private:
    int islandArea;
    int direction[4][2] = {
        {1, 0},
        {0, 1},
        {0, -1},
        {-1, 0}
    };

    void dfs(vector<vector<int>> &grid, vector<vector<bool>> &visited, int x, int y, int mark) {
        grid[y][x] = mark;
        visited[y][x] = true;
        islandArea ++;

        for(int i = 0; i < 4; i ++) {
            int nextX = x + direction[i][0];
            int nextY = y + direction[i][1];
            if(nextX < 0 || nextX >= grid[0].size() || nextY < 0 || nextY >= grid.size()) continue;
            if(!visited[nextY][nextX] && grid[nextY][nextX]) {
                dfs(grid, visited, nextX, nextY, mark);
            }
        }
    }

    int getLargestIslandArea(vector<vector<int>> &grid, unordered_map<int, int> &gridArea) {
        int largestIslandArea = 0;
        int linkIslandArea;

        unordered_set<int> visitedGrid;
        for(int i = 0; i < grid.size(); i ++) {
            for(int j = 0; j < grid[0].size(); j ++) {
                if(grid[i][j] == 0) {
                    linkIslandArea = 1;
                    visitedGrid.clear();
                    for(int k = 0; k < 4; k ++) {
                        int nearX = j + direction[k][0];
                        int nearY = i + direction[k][1];
                        if(nearX < 0 || nearX >= grid[0].size() || nearY < 0 || nearY >= grid.size()) continue;
                        if(!visitedGrid.count(grid[nearY][nearX])) {
                            linkIslandArea += gridArea[grid[nearY][nearX]];
                            visitedGrid.insert(grid[nearY][nearX]);
                        }
                    }
                    largestIslandArea = max(largestIslandArea, linkIslandArea);
                }
            }
        }
        return largestIslandArea;
    }

public:
    int buildTheLargestIsland(vector<vector<int>> &grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        unordered_map<int, int> gridArea;
        bool isAllGrid = true;

        int gridMark = 2;
        for(int i = 0; i < grid.size(); i ++) {
            for(int j = 0; j < grid[0].size(); j ++) {
                if(!grid[i][j]) isAllGrid = false;
                if(!visited[i][j] && grid[i][j]){
                    islandArea = 0;
                    dfs(grid, visited, j, i, gridMark);
                    gridArea[gridMark] = islandArea;
                    gridMark ++;
                }
            }
        }
        if(isAllGrid) return grid.size() * grid[0].size();
        else return getLargestIslandArea(grid, gridArea);
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

    cout << sol.buildTheLargestIsland(grid) << endl;
    return 0;
}