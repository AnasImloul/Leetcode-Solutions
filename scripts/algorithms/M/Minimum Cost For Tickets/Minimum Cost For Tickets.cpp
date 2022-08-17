class Solution {
public:
    int f(int i,int j,vector<int>& days,vector<int>& costs,vector<vector<int>>& dp) {
        if (i==days.size()) return 0;
        if (days[i]<j) return f(i+1,j,days,costs,dp);
        if (dp[i][j]!=-1) return dp[i][j];
        int x=costs[0]+f(i+1,days[i]+1,days,costs,dp);
        int y=costs[1]+f(i+1,days[i]+7,days,costs,dp);
        int z=costs[2]+f(i+1,days[i]+30,days,costs,dp);
        return dp[i][j]=min(x,min(y,z));
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<vector<int>> dp(days.size(),vector<int>(days[days.size()-1]+1,-1));
        return f(0,1,days,costs,dp);
    }
};
