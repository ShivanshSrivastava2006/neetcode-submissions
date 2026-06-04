class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int>mp;
        for(auto &it : nums)
            mp[it]++;
        vector<pair<int, int>>v;
        for(auto &it : mp)
            v.push_back({it.second, it.first});
        sort(v.begin(), v.end());
        int n = v.size();
        vector<int>ans;
        for(int i = 0; i < k; i++)
            ans.push_back(v[n - i - 1].second);
        return ans;
    }
};
