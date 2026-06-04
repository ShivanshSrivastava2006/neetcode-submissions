class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        while (low < high) {
            int mid = low + (high - low) / 2;
            long long time = 0;

            for (int it : piles) {
                time += (it + mid - 1) / mid; // ceil(it / mid)
            }

            if (time <= h)
                high = mid;
            else
                low = mid + 1;
        }
        return low;
    }
};
