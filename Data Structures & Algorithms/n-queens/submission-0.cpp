class Solution {
public:
    vector<vector<string>> ans;
    vector<int> queenCol;
    vector<bool> col, diag1, diag2;
    int n;

    void dfs(int row) {
        if (row == n) {
            vector<string> board(n, string(n, '.'));
            for (int r = 0; r < n; r++) {
                board[r][queenCol[r]] = 'Q';
            }
            ans.push_back(board);
            return;
        }

        for (int c = 0; c < n; c++) {
            if (col[c] || diag1[row - c + n - 1] || diag2[row + c])
                continue;

            // place
            queenCol[row] = c;
            col[c] = diag1[row - c + n - 1] = diag2[row + c] = true;

            dfs(row + 1);

            // backtrack
            col[c] = diag1[row - c + n - 1] = diag2[row + c] = false;
        }
    }

    vector<vector<string>> solveNQueens(int N) {
        n = N;
        queenCol.resize(n);
        col.assign(n, false);
        diag1.assign(2*n - 1, false);
        diag2.assign(2*n - 1, false);

        dfs(0);
        return ans;
    }
};
