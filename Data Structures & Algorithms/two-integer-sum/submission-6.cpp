class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<pair<int, int>>duplicate(n);
        for(int i = 0; i < n; i++)
            duplicate[i] = {nums[i], i};
        sort(duplicate.begin(), duplicate.end());
        int i = 0, j = n - 1;
        vector<int>ans(2);
        while(i < j)
        {
            if(duplicate[i].first + duplicate[j].first == target)
            {
                ans = {duplicate[i].second, duplicate[j].second};
                sort(ans.begin(), ans.end());
                return ans;
            }
            else if(duplicate[i].first + duplicate[j].first < target)
                i++;
            else
                j--;
        }
        return ans;
    }
};
