class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0, right = heights.size() - 1;
        long long maxarea = 0;
        while(left < right)
        {
            long long currarea = min(heights[left], heights[right])*(right - left);
            maxarea = max(maxarea, currarea);
            if(heights[left] < heights[right])
                left++;
            else
                right--;
        }
        return maxarea;
    }
};
