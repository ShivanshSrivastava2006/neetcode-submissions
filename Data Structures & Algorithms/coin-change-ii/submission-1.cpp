class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int>dp(amount+1, 0);
        dp[0] = 1;
        for(auto it : coins)
        {
            for(int i = it; i <= amount; i++)
                dp[i] += dp[i-it];
        }
        return dp[amount];
    }
};
