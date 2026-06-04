class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

        int n = intervals.size();
        vector<vector<int>> intervals2(n+1);

        auto it = upper_bound(intervals.begin(), intervals.end(), newInterval);
        int j = it - intervals.begin();

        for(int i = 0; i < j; i++)
            intervals2[i] = intervals[i];

        intervals2[j] = newInterval;

        for(int i = j+1; i <= n; i++)
            intervals2[i] = intervals[i-1];

        vector<vector<int>> ans;

        for(auto &it : intervals2)
        {
            if(ans.empty() || ans.back()[1] < it[0])
                ans.push_back(it);
            else
                ans.back()[1] = max(ans.back()[1], it[1]);
        }

        return ans;
    }
};