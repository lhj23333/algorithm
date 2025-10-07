#include <iostream> 
#include <vector>

using namespace std;

class Solution {
private:
    int direction[4][2] = {
        {1, 0},
        {0, 1},
        {0, -1},
        {-1, 0}
    };

public:
    int islandPerimeter(vector<vector<int>> &grid) {
        int perimeter = 0;

        for(int i = 0; i < grid.size(); i ++) {
            for(int j = 0; j < grid[i].size(); j ++) {
                if(grid[i][j] == 1) {
                    for(int k = 0; k < 4; k ++) {
                        int nextX = j + direction[k][0];
                        int nextY = i + direction[k][1];
                        if(nextX < 0 || nextX >= grid[i].size() || nextY < 0 || nextY >= grid.size() || !grid[nextY][nextX]) {
                            perimeter ++;
                            continue;
                        }
                    }
                }
            }
        }
        return perimeter;
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

    cout << sol.islandPerimeter(grid);
    return 0;
}