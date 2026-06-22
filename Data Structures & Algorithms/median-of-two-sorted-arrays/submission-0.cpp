class Solution {
public:
    double findMedianSortedArrays(vector<int>& A,
                  vector<int>& B)
{
    if(A.size() > B.size())
        return findMedianSortedArrays(B, A);

    int n = A.size();
    int m = B.size();

    int low = 0;
    int high = n;

    while(low <= high)
    {
        int cutA = (low + high) / 2;
        int cutB = (n + m + 1)/2 - cutA;

        int l1 =
            (cutA == 0) ? INT_MIN
                        : A[cutA-1];

        int r1 =
            (cutA == n) ? INT_MAX
                        : A[cutA];

        int l2 =
            (cutB == 0) ? INT_MIN
                        : B[cutB-1];

        int r2 =
            (cutB == m) ? INT_MAX
                        : B[cutB];

        if(l1 <= r2 && l2 <= r1)
        {
            if((n+m)%2)
                return max(l1,l2);

            return
                (max(l1,l2)
                + min(r1,r2))
                / 2.0;
        }
        else if(l1 > r2)
        {
            high = cutA - 1;
        }
        else
        {
            low = cutA + 1;
        }
    }

    return 0;
}
};
