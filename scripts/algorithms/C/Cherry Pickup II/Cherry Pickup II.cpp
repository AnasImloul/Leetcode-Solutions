// Runtime: 461 ms (Top 6.78%) | Memory: 16.8 MB (Top 51.89%)
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m, 0)));

        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < m ; j++){
                if(i==j) dp[n-1][i][j] = grid[n-1][i];
                else dp[n-1][i][j] = grid[n-1][i] + grid[n-1][j];
            }
        }
        for(int i = n-2 ; i >= 0 ; i--){
            for(int j1 = 0 ; j1 < m ; j1++){
                for(int j2 = 0 ; j2 < m ; j2++){
                    int maxi = -1e8;
                    for(int dj1 = -1 ; dj1 <= 1 ; dj1 ++){
                        for(int dj2 = -1 ; dj2 <= 1 ; dj2 ++){
                            int value = 0;
                            if(j1 == j2) value = grid[i][j2];
                            else value = grid[i][j1] + grid[i][j2];

                            if(j1+dj1 >= 0 && j1+dj1 < m && j2 +dj2 >= 0 && j2 +dj2 < m)
                                value += dp[i+1][j1+dj1][j2 +dj2];
                            else
                                value+= -1e8;
                            maxi = max(maxi,value);
                        }
                    }
                    dp[i][j1][j2] = maxi;
                }
            }
        }
        return dp[0][0][m-1];
    }
};