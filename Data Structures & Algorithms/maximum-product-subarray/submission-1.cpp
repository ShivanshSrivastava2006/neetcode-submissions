class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int minprod = nums[0];
        int maxprod = nums[0];
        int totalmax = nums[0];
        for(int i = 1; i < nums.size(); i++)
        {
            int prevmax = maxprod, prevmin = minprod;
            maxprod = max({nums[i], nums[i]*prevmax, nums[i]*prevmin});
            minprod = min({nums[i], nums[i]*prevmin, nums[i]*prevmax});
            totalmax = max(totalmax, maxprod);
        }
        return totalmax;
    }
};
