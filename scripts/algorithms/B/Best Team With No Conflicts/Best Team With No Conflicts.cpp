class Solution {
public:
    int dp[1005][1005];
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<vector<int>>grp;
        for(int i=0;i<scores.size();i++)
        {
            grp.push_back({scores[i],ages[i]});
        }
        sort(grp.begin(),grp.end());     
        memset(dp,-1,sizeof(dp));
        return recur(grp,0,ages.size(),0);
    }
    
    int recur(vector<vector<int>>&grp , int i , int n , int maxiAge)
    {
        if(i==n)
            return 0;
        if(dp[i][maxiAge]!=-1)
            return dp[i][maxiAge];
        // score is already greater than previous socre we need to check age 
        // if current age is  greater than previous maxiAge then two choices
        if(grp[i][1]>=maxiAge)
        {
            return dp[i][maxiAge] = max(grp[i][0]+recur(grp,i+1,n,grp[i][1]),recur(grp,i+1,n,maxiAge));
        }
        return dp[i][maxiAge] = recur(grp,i+1,n,maxiAge);
    }
};
