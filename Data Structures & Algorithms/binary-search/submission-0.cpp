class Solution {
public:
    int binarysearch(int low, int high, vector<int>&nums, int target)
    {
        if(low > high)
            return -1;
        int mid = (low + high)/2;
        if(nums[mid] == target)
            return mid;
        else
        {
            if(nums[mid] > target)
                return binarysearch(low, mid-1, nums, target);
            else
                return binarysearch(mid+1, high, nums, target);
        }
    }
    int search(vector<int>& nums, int target) {
        return binarysearch(0, nums.size()-1, nums, target);
    }
};
