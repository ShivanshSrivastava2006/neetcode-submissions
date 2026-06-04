class Solution {
public:
        vector<vector<int>>ans;
        vector<int>curr;
        void dfs(int i, vector<int>&nums, int target)
        {
            if(target == 0)
            {
                ans.push_back(curr);
                return;
            }
            if(i == nums.size() || target < 0)
                return;
            // pick
            curr.push_back(nums[i]);
            dfs(i, nums, target - nums[i]);
            curr.pop_back();
            // skip it
            dfs(i+1, nums, target);
        }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        dfs(0, nums, target);
        return ans;
    }
};
