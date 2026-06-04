class Solution {
public:
    vector<vector<int>>ans;
    void generator(vector<int>temp, vector<int>nums)
    {
        if(temp.size() == nums.size())
            ans.push_back(temp);
        else
        {
            set<int>s;
            for(int i = 1; i <= nums.size(); i++)
                s.insert(nums[i-1]);
            for(auto &it : temp)
            {
                s.erase(it);
            }
            for(auto &it : s)
            {
                temp.push_back(it);
                generator(temp, nums);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int>temp;
        generator(temp, nums);
        return ans;
    }
};
