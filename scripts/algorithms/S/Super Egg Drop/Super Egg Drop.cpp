// Runtime: 7 ms (Top 89.00%) | Memory: 6.1 MB (Top 94.15%)
/*
Logic Here used is:
 - we need to find, max no of floors soluiton can be found with K egg by using m move
 - recursion will use like to find m moves no of floor count we need to add dp[m-1][k-1] & dp[m-1][k];

*/

class Solution {
public:
    int superEggDrop(int k, int n) {
        vector<int> dp(k+1, 0);
        int m = 0;
        while(dp[k] < n){
            m++;
            for(int i = k; i >= 1; --i){
                dp[i] = dp[i] + dp[i-1] + 1;
            }
        }
        return m;
    }
};
