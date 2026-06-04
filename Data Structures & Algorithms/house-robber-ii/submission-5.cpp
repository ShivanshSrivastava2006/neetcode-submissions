class Solution {
public:
    int rob(vector<int>& nums) {
        // apply house roober 2 times, once leaving first house and once leaving the last house
        int n = nums.size();
        vector<int>dp(n, 0); // house robber state, maximum loot from first i+1 houses
        dp[0] = 0;
        if(n >= 3)
        {
            dp[1] = nums[1];
            dp[2] = max(nums[1], nums[2]);
            for(int i = 3; i < n; i++)
            {
                dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
            }
        }
        int maxloot = dp[n-1];
        for(auto &it : dp)
            it = 0;
        dp[0] = nums[0];
        if(n >= 2)
        {
            dp[1] = max(nums[1], nums[0]);
            for(int i = 2; i < n - 1; i++)
            {
                dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
            }
        maxloot = max(maxloot, dp[n-2]);
        }
        if(n == 1)
            maxloot = nums[0];
        if(n == 2)
            maxloot = max(nums[0], nums[1]);
        return maxloot;
    }
};
