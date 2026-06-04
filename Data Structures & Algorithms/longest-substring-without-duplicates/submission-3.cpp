class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxlength = 0;
        int i = 0;
        int n = s.length();
        while(i < s.length())
        {
            int j = i;
            unordered_map<char, int>mp;
            int currlength = 0;
            while(j < n && mp.find(s[j]) == mp.end())
            {
                mp[s[j]] = j;
                currlength++, j++;
            }
            maxlength = max(maxlength, currlength);
            if(j < n)
            {
                i = mp[s[j]] + 1;
            }
            else
                i = j;
        }
        return maxlength;
    }
};
