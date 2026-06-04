class Solution {
public:
    int countSubstrings(string s) 
    {
        int n = s.length();
        if (n == 0) return 1;

        vector<vector<bool>> dp(n, vector<bool>(n, false));

        // base case
        for (int i = 0; i < n; i++)
            dp[i][i] = true;

        int count = 0;

        // fill by increasing length
        for (int i = n - 1; i >= 0; i--) 
        {
            for (int j = i + 1; j < n; j++) 
            {
                if (s[i] == s[j] && (j - i <= 2 || dp[i+1][j-1])) 
                {
                    dp[i][j] = true;
                }
            }
        }
        for (int i = n - 1; i >= 0; i--) 
        {
            for (int j = i; j < n; j++) 
            {
                if(dp[i][j])
                    count++;
            }
        }
        return count;
    }
};
