class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n, 0);
        stack<int> st; // stores indices

        for(int i = 0; i < n; i++) {

            // answer all colder days waiting in stack
            while(!st.empty() && temperatures[i] > temperatures[st.top()]) {
                int prev = st.top();
                st.pop();
                ans[prev] = i - prev;
            }

            // this day waits for a hotter future
            st.push(i);
        }
        return ans;
    }
};
