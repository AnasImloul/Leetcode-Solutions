// Runtime: 218 ms (Top 30.21%) | Memory: 35.1 MB (Top 10.13%)
class Solution {
public:

    int fun( int i , int k , int p , vector<int>& rollMax ,vector< vector< vector<int> > > &dp){
        if(i==0) return 1;
        if(dp[i][k][p]!=-1){
            return dp[i][k][p] ;
        }
         long long int ans=0 ;
        for(int j=1 ; j<7 ; j++){
            if(j==k){
            if(p<rollMax[j-1]) ans=(ans+fun(i-1,j,p+1,rollMax,dp))%1000000007 ;
            }

            else ans=(ans+fun(i-1,j,1,rollMax,dp))%1000000007 ;
        }
        return dp[i][k][p]=ans ;
    }

    int dieSimulator(int n, vector<int>& rollMax) {
       vector< vector< vector<int> > > dp(n+1, vector< vector<int> >(7 , vector<int>(16,-1)));
        int ans=fun(n,0,1,rollMax,dp) ;
        return ans ;
    }
};