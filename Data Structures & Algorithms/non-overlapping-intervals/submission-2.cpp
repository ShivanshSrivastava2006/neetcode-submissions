class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        vector<vector<int>>vec(intervals.begin(), intervals.end());
        sort(vec.begin(), vec.end(), [](const vector<int> &a, const vector<int> &b) {
        return a[1] < b[1];
        });
        int count = 0;
        int n = vec.size();
        int last = INT_MIN;
        for(int i = 0; i < n; i++)
        {
            if(last > vec[i][0])
                count++;
            else
                last = vec[i][1];
        }
        return count;
    }
};
