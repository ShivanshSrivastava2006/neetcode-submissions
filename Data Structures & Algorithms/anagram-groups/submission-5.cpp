class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<pair<string, int>> strd;
        int i = 0;
        for(auto it : strs)
        {
            strd.push_back({it, i});
            i++;
        }
        for(auto &it : strd)
        {
            sort((it.first).begin(), (it.first).end());
        }
        sort(strd.begin(), strd.end());
        i = 0;
        vector<vector<string>>ans;
        while(i < strs.size())
        {
            vector<string>ans1;
            int j = i;
            while(j < strs.size() && strd[i].first == strd[j].first)
            {
                ans1.push_back(strs[strd[j].second]);
                j++;
            }
            i = j;
            ans.push_back(ans1);
        }
        return ans;
    }
};
