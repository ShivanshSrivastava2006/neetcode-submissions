class Solution {
public:
    vector<string> ans;
    vector<string> mp = {
        "", "", "abc", "def", "ghi",
        "jkl", "mno", "pqrs", "tuv", "wxyz"
    };

    void dfs(int i, string &digits, string &curr) {
        // BASE CASE
        if (i == digits.size()) {
            ans.push_back(curr);
            return;
        }

        int digit = digits[i] - '0';

        for (char ch : mp[digit]) {
            curr.push_back(ch);          // choose
            dfs(i + 1, digits, curr);    // explore
            curr.pop_back();             // un-choose (BACKTRACK)
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return ans;

        string curr = "";
        dfs(0, digits, curr);
        return ans;
    }
};
