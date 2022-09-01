// Runtime: 355 ms (Top 76.39%) | Memory: 43.3 MB (Top 89.82%)
class Solution {
public:
    int mod = 1000000007;
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    int countPaths(vector<vector<int>>& grid) {
        vector <vector <int>> dp(grid.size(),vector<int>(grid[0].size(),-1));
        long long count = 0;
        for(int i = 0; i<grid.size(); i++){
            for(int j = 0; j<grid[0].size(); j++){
                count = (count%mod + dfs(i,j,grid,dp)%mod)%mod;
            }
        }
        return (int)count%mod;
    }
protected:
    bool isvalid(int x, int y, vector<vector<int>>&grid){
        if(x<0 or x>=grid.size() or y<0 or y>=grid[0].size()) return false;
        return true;
    }
    int dfs(int x, int y, vector <vector<int>>&grid,vector <vector<int>>&dp){
        if(dp[x][y]!=-1) return dp[x][y];

        int ans = 1;
        for(int i = 0; i<4; i++){
            if(isvalid(x+dx[i],y+dy[i],grid) and grid[x][y]>grid[x+dx[i]][y+dy[i]]){
                ans = (ans%mod+dfs(x+dx[i],y+dy[i],grid,dp)%mod)%mod;
            }
        }
        return dp[x][y] = ans%mod;
    }
};