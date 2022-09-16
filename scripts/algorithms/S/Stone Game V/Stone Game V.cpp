// Runtime: 1664 ms (Top 43.66%) | Memory: 10.6 MB (Top 82.68%)
class Solution {
public:
    int dp[501][501];

    int f(vector<int> &v,int i,int j){

        if(i>=j) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        int r=0;
        for(int k=i;k<=j;k++) r+=v[k];

        int l=0,ans=0;
        for(int k=i;k<=j;k++){
            l+=v[k];
            r-=v[k];
            if(l<r) ans=max(ans,l+f(v,i,k));
            else if(r<l) ans=max(ans,r+f(v,k+1,j));
            else ans=max(ans,max(l+f(v,i,k),r+f(v,k+1,j)));
        }
        return dp[i][j]=ans;
    }

    int stoneGameV(vector<int>& stoneValue) {

        memset(dp,-1,sizeof(dp));
        return f(stoneValue,0,stoneValue.size()-1);

    }
};