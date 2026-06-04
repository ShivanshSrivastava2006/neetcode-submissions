class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1;
        int prodw0 = 1;
        int numz = 0;
        for(auto &it : nums)
        {
            product *= it;
            if(it != 0) prodw0 *= it;
            if(it == 0)
                numz++;
        }
        vector<int>ans;
        for(auto &it : nums)
        {
            if(it != 0)
                ans.push_back(product/it);
            else
            {
                if(numz == 1)
                    ans.push_back(prodw0);
                else
                    ans.push_back(0);
            }
        }
        return ans;
    }
};
