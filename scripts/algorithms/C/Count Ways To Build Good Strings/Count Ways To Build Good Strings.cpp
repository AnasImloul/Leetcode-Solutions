// Runtime: 12 ms (Top 60.7%) | Memory: 23.34 MB (Top 11.0%)

class Solution {
public:
    long long  helper(int length,int high,vector<long long>& dp,int low,int zero,int one) {
        long long mod = 1e9 + 7; // mod

        if(length > high) // base case if the current index overflows
            return 0;

        if(dp[length] != -1) // check if the subproblem is already computed no need to perform recursion and return the count
            return dp[length];
        
        dp[length] = length >= low ? 1 : 0; // checking the length is greater than the lower bound 

        dp[length] += helper(length + zero,high,dp,low,zero,one) + helper(length + one,high,dp,low,zero,one);
        /* now calculating the total count of that index : length  which equals to the sum for the subproblem length  +  zero and length + one
        */

        return dp[length] % mod; // now return the count with mod


    }
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<long long> dp(high + 1,-1);

        return helper(0,high,dp,low,zero,one);
    }
};