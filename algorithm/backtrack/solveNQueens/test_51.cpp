#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution {
private:
    vector<vector<string>> result;

    bool isVaild(vector<string> &chessboard, int row, int col, int n) {
        // 行检查
        for(int i = 0; i < row; i ++) {
            if(chessboard[i][col] == 'Q') return false;
        }
        // 135°检查
        for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; i --, j --) {
            if(chessboard[i][j] == 'Q') return false;
        }
        // 45°检查
        for(int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j ++) {
            if(chessboard[i][j] == 'Q') return false;
        }
        return true;
    }

    void backtracking(vector<string> &chessboard, int n ,int row) {
        if(row == n) {
            result.push_back(chessboard);
            return;
        }

        for(int i = 0; i < n; i ++){
            if(isVaild(chessboard, row, i, n)) {
                chessboard[row][i] = 'Q';
                backtracking(chessboard, n, row + 1);
                chessboard[row][i] = '.';
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        result.clear();
        vector<string> chessboard(n, string(n, '.'));
        backtracking(chessboard, n, 0);
        return result;
    }
};

static string repr(const vector<vector<string>>& sols) {
    ostringstream oss;
    oss << "[";
    for(size_t i = 0; i < sols.size(); ++i) {
        if(i) oss << ", ";
        oss << "[";
        for(size_t j = 0; j < sols[i].size(); ++j) {
            if(j) oss << ", ";
            oss << "\"" << sols[i][j] << "\"";
        }
        oss << "]";
    }
    oss << "]";
    return oss.str();
}

int main(){
    Solution sol;

    struct Test { int n; vector<vector<string>> expected; };
    vector<Test> tests = {
        {1, { {"Q"} }},
        {2, {}},
        {3, {}},
        {4, {
            {".Q..","...Q","Q...","..Q."},
            {"..Q.","Q...","...Q",".Q.."}
        }}
    };

    for(const auto &t : tests) {
        auto actual = sol.solveNQueens(t.n);
        cout << "n = " << t.n << " Actual: " << repr(actual) << "\n";
        cout << "n = " << t.n << " Expected: " << repr(t.expected) << "\n";
        cout << "Match: " << (actual == t.expected ? "true" : "false") << "\n\n";
    }

    return 0;
}