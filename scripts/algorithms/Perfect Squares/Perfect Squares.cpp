class Solution {
public:
    int numSquares(int n) {
        
        vector<int> perfectSq;
        
        for(int i = 1; i*i <= n; ++i){
            perfectSq.push_back(i*i);
        }
        
        int m = perfectSq.size();
        vector<vector<int>> dp( m+1, vector<int>(n+1, 0));
        
        dp[0][0] = 0;
        for( int i = 1; i <= n; ++i ) dp[0][i] = INT_MAX;
        
        for(int i = 1; i <= m; ++i){
            for(int j = 1; j <= n; ++j){
                
                if( j < perfectSq[i-1]){
                    dp[i][j] = dp[i-1][j];
                }
                else{
                    dp[i][j] = min( dp[i-1][j], dp[i][ j - perfectSq[i-1] ] + 1);
                }
                
            }
        }
   
        return dp[m][n];
    }
};
