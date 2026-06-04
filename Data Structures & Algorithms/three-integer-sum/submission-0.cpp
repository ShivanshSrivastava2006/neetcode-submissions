#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int i = 0;
        vector<vector<int>>ans;
        set<vector<int>>ans1;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        while(i < n)
        {
            int j = i + 1;
            int k = n - 1;
            int target = -1*nums[i];
            while(j < k)
            {
                if(nums[j] + nums[k] == target)
                {
                    vector<int>temp = {nums[i], nums[j], nums[k]};
                    sort(temp.begin(), temp.end());
                    ans1.insert(temp);
                    j++, k--;
                }
                else if(nums[j] + nums[k] < target)
                    j++;
                else
                    k--;
            }
            i++;
        }
        for(auto tuple3 : ans1)
        {
            ans.push_back(tuple3);
        }
        return ans;
    }
};
