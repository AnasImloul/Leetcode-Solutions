
class Solution {
public:
   int dp[102][102][102];
    int mod=1e9+7;
    int solve(int i,int currPeople, int currProfit,int totalP, int minProfit, vector<int>& group, vector<int>& profit)
    {
        if(i==profit.size())
        {
            if(currProfit>=minProfit and totalP>=currPeople) return 1;
            return 0;
        }
        else if(totalP<currPeople) return 0;
     
        if(dp[i][currPeople][currProfit]!=-1) return  dp[i][currPeople][currProfit];
        int include=0,notInclude=0;
        notInclude= solve(i+1,currPeople,currProfit,totalP,minProfit,group,profit);
        include=solve(i+1,currPeople+group[i],min(currProfit+profit[i],minProfit),totalP,minProfit,group,profit);
        return  dp[i][currPeople][currProfit] = (include  % mod + notInclude  % mod )%mod;
    }
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,0,n,minProfit,group,profit);
        
    }
};
