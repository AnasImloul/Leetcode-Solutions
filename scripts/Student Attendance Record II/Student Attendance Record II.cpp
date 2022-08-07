class Solution {
public:
    int mod = 1e9+7;
    int dp[100001][10][10];
    int recur(int abs,int late,int n){
        if(abs > 1){
            return 0;
        }
        if(late >= 3){
            return 0;
        }
        if(n == 0){
            return 1;
            
        }
        if(dp[n][late][abs] != -1) return dp[n][late][abs];
        
        int ans = 0;
        ans = (ans%mod + recur(abs+1,0,n-1)%mod)%mod;
        
        ans = (ans%mod + recur(abs,late+1,n-1)%mod)%mod;
        
        ans = (ans%mod + recur(abs,0,n-1)%mod)%mod;
       //This dp is running from n to 0 and is cut off if
        //absent is greater than 1 or late of consecutive is greater than
        //equal to 3.
        //Here in the first recursion i.e line 19 & line 23 late is made 0
        //to signify that the consecutive lates are stopped.***

        return dp[n][late][abs] = ans;
    }
    int checkRecord(int n) {
        for(int i=0;i<=100000;i++){
            for(int j=0;j<10;j++){
                for(int k=0;k<10;k++){
                    dp[i][j][k] = -1;
                }
            }
        }
        return recur(0,0,n);
    }
};
