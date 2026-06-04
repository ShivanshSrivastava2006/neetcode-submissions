class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        if(n < 0)
        {
            x = 1.0/x;
            n = abs(n);
        }
        while(n)
        {
            if(n&1==1)
                ans = ans*x;
            x = x*x;
            n=n>>1;
        }
        return ans;
    }
};
