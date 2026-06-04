class Solution {
public:

    string encode(vector<string>& strs) {
        string str = "";
        for(auto it : strs)
        {
            if (it.length() == 0) 
            {
                str += "0#";
                continue;
            }
            int n = it.length();
            string temp = "";
            while(n > 0)
            {
                temp += '0' + n%10;
                n /= 10;
            }
            reverse(temp.begin(), temp.end());
            str += temp;
            str += '#';
            str += it;
        }
        string s = str;
        return s;
    }

    vector<string> decode(string s) {
        vector<string>ans;
        int i = 0;
        while(i < s.length())
        {
            int j = i + 1;
            string temp = "";
            temp += s[i];
            while(j < s.length() && s[j] != '#')
            {
                temp += s[j];
                j++;
            }
            int ten = 1;
            int n = 0;
            int x = temp.length();
            while(x--)
            {
                n += (temp[x] - '0')*ten;
                ten *= 10;
            }
            string gen = "";
            while(n--)
            {
                gen += s[++j];
            }
            ans.push_back(gen);
            i = j + 1;
        }
        return ans;
    }
};
