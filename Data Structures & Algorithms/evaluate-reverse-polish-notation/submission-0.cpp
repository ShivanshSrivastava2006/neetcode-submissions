class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> store;

        for (auto &it : tokens) {
            if (it == "+" || it == "-" || it == "*" || it == "/") {
                int a = store.top(); store.pop();
                int b = store.top(); store.pop();

                if (it == "+") store.push(b + a);
                else if (it == "-") store.push(b - a);
                else if (it == "*") store.push(b * a);
                else if (it == "/") store.push(b / a);
            } 
            else {
                store.push(stoi(it));
            }
        }
        return store.top();
    }
};
