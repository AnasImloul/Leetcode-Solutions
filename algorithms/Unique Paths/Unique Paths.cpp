#define vi vector<int>
#define vvi vector<vi>
class Solution {
public:
    
    int countPath(vvi& dp,int r,int c, int m , int n){
          if(m==r-1 || n==c-1)
              return 1;
           
        if(dp[m][n]!=-1)
            return dp[m][n];
        
       return dp[m][n] = countPath(dp,r,c,m+1,n) + countPath(dp,r,c,m,n+1);
    }
    int uniquePaths(int m, int n) {
        
        vvi dp(m,vi(n,-1));
        
        return countPath(dp,m,n,0,0);
    }
};
