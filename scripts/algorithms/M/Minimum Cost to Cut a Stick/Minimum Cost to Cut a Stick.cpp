// Runtime: 233 ms (Top 8.43%) | Memory: 10.3 MB (Top 39.50%)
class Solution {
public:
    long cutMin(int i, int j, vector<int>&c, vector<vector<int>>&dp)
    {
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        long mini = INT_MAX;
        for(int ind=i;ind<=j;ind++)
        {
            long cost = c[j+1]-c[i-1]+cutMin(i,ind-1,c,dp)+cutMin(ind+1,j,c,dp);
            mini = min(mini,cost);
        }
        return dp[i][j] = mini;
    }
    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        vector<vector<int>>dp(c+1,vector<int>(c+1,-1));
        return cutMin(1,c,cuts,dp);
    }
};