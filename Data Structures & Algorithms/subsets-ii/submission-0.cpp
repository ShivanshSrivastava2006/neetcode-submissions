class Solution {
public:
    vector<vector<int>> ans;
    vector<int> curr;

    void dfs(int i, vector<int>& nums) {
        // every state is a valid subset
        ans.push_back(curr);

        for (int j = i; j < nums.size(); j++) {
            if (j > i && nums[j] == nums[j-1]) continue; // skip duplicates

            curr.push_back(nums[j]);
            dfs(j + 1, nums);
            curr.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        dfs(0, nums);
        return ans;
    }
};
