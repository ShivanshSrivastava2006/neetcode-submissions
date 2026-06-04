class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // checking rows
        set<int>temp;
        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                if(board[i][j] != '.')
                {
                    if(temp.find(board[i][j] - '0') != temp.end()) return false;
                    temp.insert(board[i][j] - '0');
                }
            }
            temp.clear();
        }
        // checking columns
        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                if(board[j][i] != '.')
                {
                    if(temp.find(board[j][i] - '0') != temp.end()) return false;
                    temp.insert(board[j][i] - '0');
                }
            }
            temp.clear();
        }
        // checking all boxes
        for(int i = 0; i < 9; i++)
        {
            // startindex = (i/3 * 3, i%3*3);
            int startrow = i/3 * 3;
            int startcolumn = i%3 * 3;
            for(int row = 0; row < 3; row++)
            {
                for(int column = 0; column < 3; column++)
                {
                    if(board[startrow + row][startcolumn + column] != '.')
                    {
                        if(temp.find(board[startrow + row][startcolumn + column] - '0') != temp.end()) return false;
                        temp.insert(board[startrow + row][startcolumn + column] - '0');
                    }
                }
            }
            temp.clear();
        }
        return true;
    }
};
