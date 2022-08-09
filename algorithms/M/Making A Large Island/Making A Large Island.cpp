class Solution {
    int dir[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
    
    bool isValid(vector<vector<int>>const &grid,vector<vector<int>> &visited, int row, int col){
        int n=grid.size();
        
        if(row<0 || row>=n || col<0 || col>=n || grid[row][col]!=1 || visited[row][col]!=0){
            return false;
        }
        return true;
    }
    
    int helper(vector<vector<int>>const &grid,vector<vector<int>> &visited, int row, int col){
        
        if(!isValid(grid,visited,row,col)) return 0;
        
        visited[row][col]=1;
            
       
           
       return 1+helper(grid,visited, row+dir[0][0], col+dir[0][1])+
                helper(grid,visited, row+dir[1][0], col+dir[1][1])+
                helper(grid,visited, row+dir[2][0], col+dir[2][1])+
                helper(grid,visited, row+dir[3][0], col+dir[3][1]);
        
        return 0;
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        int ans=0;
        int n=grid.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<grid.size();j++){
                
                if(grid[i][j]==0){
                    grid[i][j]=1;
                    vector<vector<int>> visited(n,vector<int>(n,0));
                    ans=max(ans,helper(grid,visited, i,j));
                    grid[i][j]=0;
                }
                
            }
        }
        return ans==0?n*n:ans;
    }
};
