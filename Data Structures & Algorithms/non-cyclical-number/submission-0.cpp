class Solution {
public:
    bool isHappy(int n) {
        int temp = 0;
        for(int i = n; i > 0; i /= 10)
            temp += (i % 10)*(i % 10);
        // now we need to check if using this sum.. we can get to 10, 100 or 1000 at some point
        while(temp/10 > 0)
        {
            int temp2 = temp;
            int sum = 0;
            while(temp2 > 0)
            {
                sum += (temp2 % 10) * (temp2 % 10);
                temp2 /= 10;
            }
            temp = sum;
        }
        if(temp == 1)
            return true;
        else
            return false;
    }
};
