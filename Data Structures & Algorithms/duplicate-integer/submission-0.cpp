class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int>s;
        for(auto it : nums)
            s.insert(it);
        if(s.size() == nums.size())
            return false;
        return true;
    }
};