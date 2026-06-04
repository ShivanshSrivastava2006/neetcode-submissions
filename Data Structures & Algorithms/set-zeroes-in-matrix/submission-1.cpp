class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i = 0; i < n; i++)
        {
            int count = 0;
            for(int j = 0; j < m; j++)
            {
                if(matrix[i][j] == 0)
                {
                    count++;
                }
            }
            if(count > 0)
            {
                // means this row needs to be made zero.
                for(int j = 0; j < m; j++)
                {
                    if(matrix[i][j] == 0)
                    {
                        matrix[i][j] = -1;
                    }
                    else
                        matrix[i][j] = 0;
                }
            }
        }
        for(int j = 0; j < m; j++)
        { // iterating rows over columns
            for(int i = 0; i < n; i++)
            {
                if(matrix[i][j] == -1)
                {
                    for(int k = 0; k < n; k++)
                    {
                        matrix[k][j] = 0;
                    }
                }
            }
        }
    }
};
