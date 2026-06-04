class Solution {
public:
    int reverse(int x) {
        long long tx = x;          // widen FIRST
        if (tx < 0) tx = -tx;      // safe negation

        string str = to_string(tx);
        std::reverse(str.begin(), str.end());

        long long ans = stoll(str);
        if (x < 0) ans = -ans;

        if (ans < INT_MIN || ans > INT_MAX)
            return 0;

        return (int)ans;
    }
};
