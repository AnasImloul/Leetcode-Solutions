class Solution {
public:
    
    int check( int i , int j , int n  ){
        if( i <0  || j<0 || i>=n || j>=n )
            return 0;
        return 1;
    }
    
    int solve(vector<vector<int>>&mat , int i , int j  , int n , vector<vector<int>>&dp ){
        
        if(not check( i , j , n ))
            return 999999;
        
        if(i == n-1 && j < n  )return mat[i][j];
        
        if(dp[i][j]!= -1 )
            return dp[i][j];
        
        
        int op_1 = mat[i][j] + solve(mat , i+1,  j - 1 , n , dp );
        int op_2 = mat[i][j] + solve(mat , i+1 , j  ,    n , dp );
        int op_3 = mat[i][j] + solve(mat , i+1 , j + 1 , n , dp );
        
        
        return dp[i][j] =  min( {op_1 , op_2 , op_3} );
        
        
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix[0].size();
        
//         vector<vector<int>>dp(n+1 , vector<int>(n +1 , -1 ));
//         int ans =  INT_MAX;
//         for(int i = 0  ; i<n ; ++i )
//             ans = min( ans , solve( matrix , 0, i , n , dp ));
        
        
        
        vector<vector<int>>dp(n , vector<int>(n, 0));
        for( int i =0  ; i<n ; ++i )
            dp[0][i] = matrix[0][i];
        
        
        for( int i =1 ; i<n ; ++i ){
            for( int j = 0  ; j<n ; ++j ){
                
                if(j-1>=0 && j+1 < n )
                    dp[i][j] = matrix[i][j] + min( {dp[i-1][j-1] ,  dp[i-1][j] , dp[i-1][j+1] });
                else if(j == 0 )
                     dp[i][j] = matrix[i][j] + min( { dp[i-1][j] , dp[i-1][j+1] });
                else if(j == n-1 )
                     dp[i][j] = matrix[i][j] + min( {dp[i-1][j-1] ,  dp[i-1][j] });
            }
        }
        
        int ans = INT_MAX;
        for( int i = 0  ; i<n ; ++i )
            ans = min( ans , dp[n-1][i]);
        
        
        
        
        return ans ;
    }
};
