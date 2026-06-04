class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0") return "0";

        int n = num1.length();
        int m = num2.length();
        vector<int> carry(n + m + 1, 0);

        for(int k = 0; k < n + m; k++) {
            int i, j;
            if(k < m) i = 0, j = k;
            else i = k - m + 1, j = m - 1;

            while(i < n && j >= 0) {
                carry[k] += (num1[n - 1 - i] - '0') * (num2[m - 1 - j] - '0');
                i++; j--;
            }

            carry[k + 1] += carry[k] / 10;
            carry[k] %= 10;
        }

        string ans = "";
        int idx = n + m;
        while(idx > 0 && carry[idx] == 0) idx--;

        for(int i = idx; i >= 0; i--)
            ans.push_back(carry[i] + '0');

        return ans;
    }
};
