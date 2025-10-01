#include <iostream>
#include <vector>

using namespace std;

#define SIZE 9

bool isVaild(int grid[SIZE][SIZE], size_t row, size_t col, int num){
    for(size_t i = 0; i < SIZE; i ++) {
        if(grid[row][i] == num) return false;
    }
    for(size_t i = 0; i < SIZE; i ++) {
        if(grid[i][col] == num) return false;
    }

    int startRow = row/3*3;
    int startCol = col/3*3;
    for(size_t i = startRow; i < startRow + 3; i ++) {
        for(size_t j = startCol; j < startCol + 3; j ++) {
            if(grid[i][j] == num) return false;
        }
    }
    return true;
}

bool solveSudoku(int grid[SIZE][SIZE]) {
   for(size_t i = 0; i < SIZE; i ++) {
        for(size_t j = 0; j < SIZE; j ++) {
            if(grid[i][j] != 0) continue;
            for(int num = 1; num <= 9; num ++) {
                if(isVaild(grid, i, j, num)) {
                    grid[i][j] = num;
                    if(solveSudoku(grid)) return true;
                    grid[i][j] = 0;
                }
            }
            return false;
        }
    }
    return true;
}

void printfSudoku(int grid[SIZE][SIZE]) {
    for(size_t i = 0; i < SIZE; i ++) {
        for(size_t j = 0; j < SIZE; j ++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int grid[9][9] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };
    if(solveSudoku(grid)) {
        printf("数独解决方案:\n");
        printfSudoku(grid);
    } else {
        printf("没有找到解决方。\n");
    }
    return 0;
}