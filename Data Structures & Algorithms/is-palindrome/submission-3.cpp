class Solution {
public:
    bool isPalindrome(string s) {
        string str = "";
        for(int i = 0; i < s.length(); i++)
        {
            if((s[i] - 'A' < 26 && s[i] - 'A' >= 0) || (s[i] - 'a' < 26 && s[i] - 'a' >= 0) || (s[i] - '0' < 10 && s[i] - '0' >= 0))
                str += s[i];
        }
        int i = 0, j = str.length() - 1;
        while(i < j)
        {
            if((str[i] != str[j] && (str[i] != str[j] - 32) && (str[i] != str[j] + 32)) || ((str[i] - 'A' + 1)*(str[j] - 'A' + 1) < 0))
                return false;
            i++, j--;
        }
        return true;
    }
};
