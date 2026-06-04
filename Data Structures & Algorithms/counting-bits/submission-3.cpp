class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>dp(n+1, 0);
        if(n >= 1)
        {
            dp[1] = 1;
            for(int i = 1; i <= n; i *= 2)
            {
                dp[i] = 1;
            }
            int k = 2; // the power of 2 less than i;
            for(int i = 3; i <= n; i++)
            {
                if(i >= k*2)
                    k *= 2;
                if((i & (i-1)) != 0)
                    dp[i] = dp[i-k] + 1;
            }
            return dp;
        }
        else
            return {0};
    }
};
