class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int>mp; // for O(1) average look-up
        for(int i = 0; i < n; i++)
        {
            int need = target - nums[i];
            if(mp.count(need))
                return {mp[need], i};
            else
                mp[nums[i]] = i;
        }
        
    }
};
