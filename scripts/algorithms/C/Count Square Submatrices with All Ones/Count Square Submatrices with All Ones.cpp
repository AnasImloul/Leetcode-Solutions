// Runtime: 95 ms (Top 67.19%) | Memory: 28.9 MB (Top 5.13%)
class Solution {
public:

    int solve( vector<vector<int>>&mat , int n , int m , vector<vector<int>>&dp){

        if(n<0 or m<0 or mat[n][m] == 0 )
            return 0;

        if(dp[n][m] != -1 )
            return dp[n][m];

        return dp[n][m] = ( 1 + min({
            solve( mat , n-1 , m , dp ),
            solve(mat , n-1 , m-1 , dp ),
            solve(mat , n , m-1 , dp )
        }));

    }

    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = 0 ;

        // vector<vector<int>>dp(n , vector<int>(m,-1));
        // for(int i = 0 ; i<n ; ++i ){
        // for(int j= 0 ; j<m ; ++j ){
        // ans += solve( matrix,i , j , dp );
        // }
        // }

        vector<vector<int>>dp(n , vector<int>(m, 0));

        for(int i = 0 ; i<n ; ++i ){
            for(int j = 0 ; j<m ; ++j ){
                if(i==0 || j ==0 ){
                    dp[i][j] = matrix[i][j];
                }
                else{
                    if(matrix[i][j])
                        dp[i][j] = 1 + min({dp[i-1][j] , dp[i-1][j-1] , dp[i][j-1]});
                }
            }
        }

        for(auto x : dp ){
            for(auto y : x )
                ans += y;
        }

        return ans ;
    }
};