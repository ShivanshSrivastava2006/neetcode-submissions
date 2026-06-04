class Solution {
public:
    int getSum(int a, int b) {
        int ans = a xor b;
        ans += 2*(a&b);
        return ans;
    }
};
