class Solution {
public:
    int dp[103][103][2];
    int rec(int i,int m,int p,vector<int>& piles){
        if(i==piles.size()) return 0;
        if(dp[i][m][p]!=-1) return dp[i][m][p];
        int cnt = 0,ans=INT_MIN,n=piles.size();
        for(int j=i;j<min(n,i+2*m);j++){
            cnt += piles[j];
            ans =max(ans, cnt - rec(j+1,max(j-i+1,m),1-p,piles));
        }
        return dp[i][m][p] = ans;
    }
    int stoneGameII(vector<int>& piles) {
        int sum = 0;
        memset(dp,-1,sizeof(dp));
        for(auto i:piles) sum += i;
        return (sum + rec(0,1,0,piles))/2;
    }
};
