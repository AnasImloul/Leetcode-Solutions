// Runtime: 95 ms (Top 78.34%) | Memory: 11.2 MB (Top 58.34%)
class Solution {
    int dp[101][22][101];
    vector<int> h;//m
    vector<vector<int>> c;//n
    int mm; int nn; int t;
    int dfs(int idx, int prev, int curt){
        if(curt<1)
            return INT_MAX;
        if(idx==mm)
            return (curt==1)?0:INT_MAX;
        if(dp[idx][prev][curt]!=-1)
            return dp[idx][prev][curt];
        int res=INT_MAX;
        int color=h[idx];
        if(color==0){
            for(int x=0;x<nn;x++){
                color=x+1;
                int rres=dfs(idx+1,color,curt-(prev!=21 and prev!=color));
                if(rres!=INT_MAX)
                    res=min(c[idx][color-1]+rres,res);
            }
        }else{
            return dp[idx][prev][curt]=dfs(idx+1,color,curt-(prev!=21 and prev!=color));
        }
        return dp[idx][prev][curt]=res;
    }
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        h=houses,c=cost,mm=m,nn=n,t=target;
        memset(dp,-1,sizeof(dp));
        int res=dfs(0,21,t);
        return res==INT_MAX?-1:res;
    }
};