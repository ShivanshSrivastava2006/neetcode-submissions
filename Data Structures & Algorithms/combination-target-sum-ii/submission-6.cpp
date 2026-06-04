class Solution {
public:
    vector<vector<int>> ans;
    vector<int> curr;

    void sum(int i, vector<int>& nums, int target)
    {
        if(target == 0)
        {
            ans.push_back(curr);
            return;
        }

        if(i == nums.size())
            return;

        // take it
        if(nums[i] <= target)
        {
            curr.push_back(nums[i]);
            sum(i + 1, nums, target - nums[i]);
            curr.pop_back();
        }

        // skip duplicates while not taking
        int j = i + 1;
        while(j < nums.size() && nums[j] == nums[i])
            j++;

        sum(j, nums, target);
    }

    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        sum(0, nums, target);
        return ans;
    }
};