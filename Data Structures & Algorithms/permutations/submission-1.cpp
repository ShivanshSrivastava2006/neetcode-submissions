class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    vector<bool> used;

    void dfs(vector<int>& nums) {
        // base case: permutation complete
        if (path.size() == nums.size()) {
            ans.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) continue;

            // choose
            used[i] = true;
            path.push_back(nums[i]);

            // explore
            dfs(nums);

            // un-choose (backtrack)
            path.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        used.resize(nums.size(), false);
        dfs(nums);
        return ans;
    }
};
