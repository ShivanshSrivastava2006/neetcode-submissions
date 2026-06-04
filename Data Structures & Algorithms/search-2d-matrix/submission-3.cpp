class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        if(matrix.empty() || matrix[0].empty())
            return false;

        int low = 0, high = matrix.size() - 1;
        int row = -1;

        // find row
        while(low <= high)
        {
            int mid = low + (high - low)/2;
            if(matrix[mid][0] <= target)
            {
                row = mid;
                low = mid + 1;
            }
            else
                high = mid - 1;
        }

        if(row == -1)
            return false;

        int i = row;

        if(matrix[i][0] == target)
            return true;

        // search inside row
        low = 0;
        high = matrix[0].size() - 1;

        while(low <= high)
        {
            int mid = low + (high - low)/2;
            if(matrix[i][mid] <= target)
                low = mid + 1;
            else
                high = mid - 1;
        }

        if(high >= 0 && matrix[i][high] == target)
            return true;

        return false;
    }
};
