// Runtime: 50 ms (Top 83.42%) | Memory: 7.9 MB (Top 52.59%)
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