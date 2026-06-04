class Solution {
public:
    vector<vector<int>>ans;
    vector<int>curr;
    void dfs(int i, vector<int>&nums)
    {
        if(i == nums.size())
        {
            ans.push_back(curr);
            return;
        }
        // take it
        curr.push_back(nums[i]);
        dfs(i+1, nums);
        curr.pop_back();
        //leave it
        dfs(i+1, nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(0, nums);
        return ans;
    }
};
