class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int column = matrix[0].size();
        
        int order = 0;
        int beginrow = 0, endrow = row - 1;
        int begincolumn = column - 1, endcolumn = 0;

        vector<int> ans;

        while (beginrow <= endrow && endcolumn <= begincolumn) {

            if (order % 4 == 0 && beginrow <= endrow) {
                for (int i = endcolumn; i <= begincolumn; i++)
                    ans.push_back(matrix[beginrow][i]);
                beginrow++;
            }

            else if (order % 4 == 1 && endcolumn <= begincolumn) {
                for (int i = beginrow; i <= endrow; i++)
                    ans.push_back(matrix[i][begincolumn]);
                begincolumn--;
            }

            else if (order % 4 == 2 && beginrow <= endrow) {
                for (int i = begincolumn; i >= endcolumn; i--)
                    ans.push_back(matrix[endrow][i]);
                endrow--;
            }

            else if (order % 4 == 3 && endcolumn <= begincolumn) {
                for (int i = endrow; i >= beginrow; i--)
                    ans.push_back(matrix[i][endcolumn]);
                endcolumn++;
            }

            order++;
        }

        return ans;
    }
};
