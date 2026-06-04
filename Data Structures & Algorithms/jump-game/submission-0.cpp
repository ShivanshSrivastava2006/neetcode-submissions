class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>>valid(n);
        for(int i = 0; i < n; i++)
            valid[i] = {nums[i], 1}; // all are valid initially
        int count = 0; // count consecutive 0s
        for(int i = n - 2; i >= 0; i--)
        {
            if(nums[i] <= count)
            {
                valid[i].second = 0;
                count++;
            }
            else
                count = 0;
        }
        if(valid[0].second == 1)
            return true;
        return false;
    }
};
