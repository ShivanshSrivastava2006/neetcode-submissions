class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        if(n >= 2)
        {
            digits[n-1] += 1;
            digits[n-2] += digits[n-1]/10; // n >= 2 is assumed.. which isn't true necessarily
            digits[n-1] %= 10;
        }
        else
        {
            digits[0] += 1;
        }
        for(int i = n-2; i > 0; i--)
        {
            digits[i-1] += digits[i]/10;
            digits[i] %= 10;
        }
        if(digits[0]/10 > 0)
        {
            vector<int>ans(n+1);
            ans[0] = digits[0]/10;
            ans[1] = digits[0] % 10;
            for(int i = 2; i <= n; i++)
            {
                ans[i] = digits[i-1];
            }
            return ans;
        }
        else
        {
            return digits;
        }
    }
};
