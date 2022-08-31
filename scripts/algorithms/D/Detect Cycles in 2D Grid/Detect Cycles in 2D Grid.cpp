// Runtime: 513 ms (Top 35.90%) | Memory: 64.7 MB (Top 53.80%)
class Solution {
public:
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,1,-1};
    bool solve(vector<vector<char>>& grid,int i,int j,int m,int n,int x,int y,vector<vector<int>>&vis,char startChar){
        vis[i][j]=1;
        for(int k=0;k<4;k++){
            int xx=i+dx[k];
            int yy=j+dy[k];
            if(xx>=0 && yy>=0 && xx<m && yy<n && grid[xx][yy]==startChar && !(x == xx && y == yy)){
              if(vis[xx][yy] || solve(grid, xx , yy , m , n, i, j,vis,startChar))
                    return true;
            }
        }
        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
     int m=grid.size();
     int n=grid[0].size();
     vector<vector<int>>vis(m,vector<int>(n,0));
     for(int i=0;i<m;i++){
         for(int j=0;j<n;j++){
             if(!vis[i][j] && solve(grid,i,j,m,n,-1,-1,vis,grid[i][j])){
                 return true;
             }
         }
     }
        return false;
    }
};