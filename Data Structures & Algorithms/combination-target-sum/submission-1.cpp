class Solution {
public:
vector<vector<int>>ans;
vector<int>curr;
    void sum(int i, vector<int>& nums, int target)
    {
        if(i == nums.size())
        {
            if(target == 0)
                ans.push_back(curr);
            return;
        }
        if(target == 0)
        {
            ans.push_back(curr);
            return;
        }
        // take it
        if(nums[i] <= target)
        {
            curr.push_back(nums[i]);
            sum(i, nums, target-nums[i]);
            curr.pop_back();
        }
        // leave it
        sum(i+1, nums, target);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sum(0, nums, target);
        return ans;
    }
};
