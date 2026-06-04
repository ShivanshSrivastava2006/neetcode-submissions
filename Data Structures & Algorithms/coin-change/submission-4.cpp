class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount + 1, INT_MAX);
        sort(coins.begin(), coins.end());
        for(int i = 0; i < coins.size() && coins[i] <= amount; i++)
        {
            dp[coins[i]] = 1;
        }
        dp[0] = 0;
        for(int i = 1; i <= amount; i++)
        {
            for(int j = 0; j < coins.size() && coins[j] <= i; j++)
                if (dp[i - coins[j]] != INT_MAX)
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);

        }
        if(dp[amount] < 0 || dp[amount] == INT_MAX)
            return -1;
        return dp[amount];
    }
};
