class Solution {
public:
    bool winnerSquareGame(int n) {
        
        vector<int> dp(n+1,false);
        
        for(int i=1;i<=n;i++){
            for(int j=sqrt(i);j>=1;j--){
                if(dp[i-j*j] == false){
                    dp[i] = true;
                    break;
                }
            }
        }
        
        return dp[n];
    }
};
