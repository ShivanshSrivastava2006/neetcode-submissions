class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i = 0;
        int maxprofit = 0;
        int n = prices.size();
        int mini = INT_MAX;
        while(i < n)
        {
            maxprofit = max(maxprofit, prices[i] - mini);
            mini = min(prices[i], mini);
            i++;
        }
        return maxprofit;
    }
};
