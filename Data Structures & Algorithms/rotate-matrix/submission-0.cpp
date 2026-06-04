class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // row 1 becomes column n, row 2 column n-1 so on..
        int temp1, temp2, temp3, temp4;
        int n = matrix[0].size();
        for(int i = 0; i < n/2; i++)
        {
            for(int j = i; j < n - i - 1; j++)
            {
                temp1 = matrix[i][j];
                temp2 = matrix[j][n-i-1];
                temp3 = matrix[n-i-1][n-j-1];
                temp4 = matrix[n-j-1][i];
                matrix[j][n-i-1] = temp1;
                matrix[n-i-1][n-j-1] = temp2;
                matrix[n-j-1][i] = temp3;
                matrix[i][j] = temp4;
            }
        } 
    }
};
