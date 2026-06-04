class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<long long, int>mp;
        for(auto &it : nums)
            mp[it] = 1;
        int maxelement = 0;
        for(auto &it : mp)
        {
            it.second += mp[it.first - 1];
            maxelement = max(maxelement, it.second);
        }
        return maxelement;
    }
};
