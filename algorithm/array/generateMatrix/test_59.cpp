#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // title：螺旋矩阵 II
    // 思路：依据区间(左闭右开）定义守恒原则，对坐标点位置移动进行约束
    vector<vector<int>> generateMatrix(int n){
        vector<vector<int>> res(n, vector<int>(n, 0));

        int loop = n / 2;             // 定义循环圈数：n/2
        int startx = 0, starty = 0;   // 定义起始坐标（0，0）
        int offset = 1;               // 定义边界偏移量：每遍历完一圈，offset ++
        int cnt = 1;                  // 计数迭代

        while(loop --)
        {
            // 采用 for 循环内定义 row、col 进行迭代 -> 使得当单边迭代结束后，位置能移动到下阶段起始位置

            // 绘制上边界
            for(int row = startx; row < n - offset; row ++)
            {
                res[starty][row] = cnt ++;
            }
            // 绘制右边界
            for(int col = starty; col < n - offset; col ++)
            {
                res[col][n - offset] = cnt ++;
            }
            // 绘制下边界
            for(int row = n - offset; row > startx; row --)
            {
                res[n - offset][row] = cnt ++;
            }
            // 绘制左边界
            for(int col = n - offset; col > starty; col --)
            {
                res[col][startx] = cnt ++;
            }
            
            // 迭代新的坐标起始点
            startx ++;          
            starty ++;

            // 迭代边界偏移量
            offset ++;          
        }
        
        // 当 n 为奇数时，需手动为中间节点位置赋值
        if(n % 2 != 0)
        {
            res[starty][startx] = cnt;
        }

        return res;
    }
};


int main()
{
    Solution solut;

    vector<vector<int>> res;
    int n = 10;

    res = solut.generateMatrix(n);

    for(int i = 0; i < n; i ++)
    {
        for(int j = 0; j < res[i].size(); j ++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}