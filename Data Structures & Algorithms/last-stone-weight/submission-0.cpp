class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq; //max_heap
        for(auto it : stones)
            pq.push(it);
        for(int i = stones.size() - 1; i > 0; i--)
        {
            int x = pq.top(); pq.pop();
            int y = pq.top(); pq.pop();
            pq.push(abs(x-y));
        }
        return pq.top();
    }
};
