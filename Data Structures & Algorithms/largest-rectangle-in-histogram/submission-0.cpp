class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

    stack<int> st;
    int ans = 0;
    int n = heights.size();

    for (int i = 0; i <= n; i++) {

        int curr = (i == n ? 0 : heights[i]);

        while (!st.empty() &&
               heights[st.top()] > curr) {

            int h = heights[st.top()];
            st.pop();

            int right = i;

            int left =
                st.empty() ? -1 : st.top();

            int width = right - left - 1;

            ans = max(ans, h * width);
        }

        st.push(i);
    }

    return ans;
}
};
