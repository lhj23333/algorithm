#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    // 判断写入数字是否有效
    bool isVaild(vector<vector<char>> &board, size_t row, size_t col, char val) {
        for(size_t i = 0; i < board[0].size(); i ++) {
            if(board[row][i] == val) return false;
        }
        
        for(size_t i = 0; i < board.size(); i ++) {
            if(board[i][col] == val) return false;
        }

        size_t startRow = row / 3 * 3;
        size_t startCol = col / 3 * 3;
        for(size_t i = startRow; i < startRow + 3; i ++) {
            for(size_t j = startCol; j < startCol + 3; j ++) {
                if(board[i][j] == val) return false;
            }
        }
        return true;
    }

    bool backtracking(vector<vector<char>> &board) {
        for(size_t i = 0; i < board.size(); i ++) {
            for(size_t j = 0; j < board[0].size(); j ++) {
                if(board[i][j] != '.') continue;
                for(char val = '1'; val <= '9'; val ++) {
                    if(isVaild(board, i, j, val)) {
                        board[i][j] = val;
                        if(backtracking(board)) return true;    // 遍历出一个解，立即返回
                        board[i][j] = '.';
                    }
                }
                return false;       // 当完全写入所有数字时，其递归依旧未找到一个解 -> false;
            }
        }
        return true;                // 完成所有遍历 -> true;
    }

public:
    void solveSudoku(vector<vector<char>> &board) {
        backtracking(board);
    }
};

static void printBoard(const vector<vector<char>>& b) {
    for (const auto& row : b) {
        for (size_t j = 0; j < row.size(); ++j) {
            cout << row[j];
            if (j + 1 < row.size()) cout << ' ';
        }
        cout << '\n';
    }
}

int main()
{
    Solution solver;

    // Test 1: Classic LeetCode example (contains '9's so it exposes the off-by-one bug)
    vector<vector<char>> board1 = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    vector<vector<char>> expected1 = {
        {'5','3','4','6','7','8','9','1','2'},
        {'6','7','2','1','9','5','3','4','8'},
        {'1','9','8','3','4','2','5','6','7'},
        {'8','5','9','7','6','1','4','2','3'},
        {'4','2','6','8','5','3','7','9','1'},
        {'7','1','3','9','2','4','8','5','6'},
        {'9','6','1','5','3','7','2','8','4'},
        {'2','8','7','4','1','9','6','3','5'},
        {'3','4','5','2','8','6','1','7','9'}
    };

    cout << "Test 1 - Solved:\n";
    solver.solveSudoku(board1);
    printBoard(board1);
    cout << "Expected:\n";
    printBoard(expected1);
    cout << (board1 == expected1 ? "PASS\n" : "FAIL\n");

    // Test 2: Single missing cell (last cell), another quick check
    vector<vector<char>> board2 = {
        {'5','3','4','6','7','8','9','1','2'},
        {'6','7','2','1','9','5','3','4','8'},
        {'1','9','8','3','4','2','5','6','7'},
        {'8','5','9','7','6','1','4','2','3'},
        {'4','2','6','8','5','3','7','9','1'},
        {'7','1','3','9','2','4','8','5','6'},
        {'9','6','1','5','3','7','2','8','4'},
        {'2','8','7','4','1','9','6','3','5'},
        {'3','4','5','2','8','6','1','7','.'} // last cell missing, should be '9'
    };
    vector<vector<char>> expected2 = {
        {'5','3','4','6','7','8','9','1','2'},
        {'6','7','2','1','9','5','3','4','8'},
        {'1','9','8','3','4','2','5','6','7'},
        {'8','5','9','7','6','1','4','2','3'},
        {'4','2','6','8','5','3','7','9','1'},
        {'7','1','3','9','2','4','8','5','6'},
        {'9','6','1','5','3','7','2','8','4'},
        {'2','8','7','4','1','9','6','3','5'},
        {'3','4','5','2','8','6','1','7','9'}
    };

    cout << "\nTest 2 - Solved:\n";
    solver.solveSudoku(board2);
    printBoard(board2);
    cout << "Expected:\n";
    printBoard(expected2);
    cout << (board2 == expected2 ? "PASS\n" : "FAIL\n");

    return 0;
}