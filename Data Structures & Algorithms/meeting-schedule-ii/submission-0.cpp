/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<pair<int, int>>v;
        int n = intervals.size();
        for(int i = 0;  i < n; i++)
        {
            v.push_back({intervals[i].start, +1});
            v.push_back({intervals[i].end, -1}); 
        }
        int count = 0;
        int maxcount = 0;
        sort(v.begin(), v.end());
        for(int i = 0; i < v.size(); i++)
        {
            count += v[i].second;
            maxcount = max(maxcount, count);
        }
        return maxcount;
    }
};
