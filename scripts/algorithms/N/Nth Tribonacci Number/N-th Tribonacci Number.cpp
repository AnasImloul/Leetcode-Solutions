// Runtime: 0 ms (Top 100.00%) | Memory: 5.8 MB (Top 83.99%)
class Solution {
public:
    int tribonacci(int n) {
        if(n<2)
            return n;

        int prev3 = 0;
        int prev2 = 1;
        int prev1 = 1;

        for(int i = 3; i<= n ; i++)
        {
            int ans = prev1+ prev2+prev3;
            prev3 = prev2;
            prev2 = prev1;
            prev1 = ans;
        }

        return prev1;
    }
};