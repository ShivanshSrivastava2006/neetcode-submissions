class Solution {
public:
    vector<vector<int>> ans;
    vector<int> curr;

    void dfs(int i, vector<int>& nums, int target) {
        if (target == 0) {
            ans.push_back(curr);
            return;
        }

        for (int j = i; j < nums.size(); j++) {
            if (j > i && nums[j] == nums[j-1]) continue; // 🔥 skip duplicates
            if (nums[j] > target) break;

            curr.push_back(nums[j]);
            dfs(j + 1, nums, target - nums[j]);
            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(0, candidates, target);
        return ans;
    }
};
