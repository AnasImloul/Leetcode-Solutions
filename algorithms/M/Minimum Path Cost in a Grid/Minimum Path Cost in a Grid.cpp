class Solution {
public:
    int solve(vector<vector<int>> &grid,vector<vector<int>>& moveCost,int i,int j,int n,int m){
        if(i==n-1){
            return grid[i][j];
        }
        int ans=INT_MAX;
        for(int k=0;k<m;k++){
            ans=min(ans,grid[i][j]+moveCost[grid[i][j]][k]+solve(grid,moveCost,i+1,k,n,m));
        }
        return ans;
    }
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int ans=INT_MAX;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<m;i++){
            ans=min(ans,solve(grid,moveCost,0,i,n,m));
        }
        return ans;
    }
};
