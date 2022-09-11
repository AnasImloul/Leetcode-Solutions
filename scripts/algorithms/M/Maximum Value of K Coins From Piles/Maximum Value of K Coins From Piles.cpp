// Runtime: 348 ms (Top 76.94%) | Memory: 19.6 MB (Top 26.02%)
class Solution {
public:
   int dp[1001][2001]; //Dp array For Memoization.
   int solve(vector<vector<int>>&v,int index,int coin)
   {
       if(index>=v.size()||coin==0) //Base Condition
           return 0;
       if(dp[index][coin]!=-1) //Check wheather It is Already Calculated Or not.
           return dp[index][coin];

       /* Our 1st choice :- We not take any Coin from that pile*/
       int ans=solve(v,index+1,coin); //Just Call function for next Pile.

       /*Otherwise we can take Coins from that Pile.*/
       int loop=v[index].size()-1;
       int sum=0;

       for(int j=0;j<=min(coin-1,loop);j++) //
       {
           sum=sum+v[index][j];
           ans=max(ans,sum+solve(v,index+1,coin-(j+1)));

           /*Aove we Pass coin-(j+1). Because till j'th index we have taken j+1 coin from that pile.*/
       }

       return dp[index][coin]=ans;
   }
   int maxValueOfCoins(vector<vector<int>>& piles, int k) {
       memset(dp,-1,sizeof(dp));
       return solve(piles,0,k);
   }
};