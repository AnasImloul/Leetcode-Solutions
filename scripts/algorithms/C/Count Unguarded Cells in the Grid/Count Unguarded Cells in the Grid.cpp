class Solution {
public:
    void dfs( vector<vector<int>> &grid,int x,int y,int m,int n,int dir){
        if(x<0 || y<0 || x>=m || y>=n) return;
        if(grid[x][y]==2 || grid[x][y]==1) return;
        grid[x][y]=3;
        if(dir==1){
            dfs(grid,x+1,y,m,n,dir);
        }
        else if(dir==2){
            dfs(grid,x,y+1,m,n,dir);
        }
        else if(dir==3){
            dfs(grid,x-1,y,m,n,dir);
        }
        else{
            dfs(grid,x,y-1,m,n,dir);
        }
    }
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
         vector<vector<int>> grid(m,vector<int>(n,0));
        //marking guards
        for(int i=0;i<guards.size();i++){
            int x=guards[i][0];
            int y=guards[i][1];
            grid[x][y]=1;
        }
        // marking walls
         for(int i=0;i<walls.size();i++){
            int x=walls[i][0];
            int y=walls[i][1];
            grid[x][y]=2;
        }
        // dfs in each of 4 directions
          for(int i=0;i<guards.size();i++){
            int x=guards[i][0];
            int y=guards[i][1];
              dfs(grid,x+1,y,m,n,1);
              dfs(grid,x,y+1,m,n,2);
              dfs(grid,x-1,y,m,n,3);
              dfs(grid,x,y-1,m,n,4);
          }
        long long int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0) cnt++;
            }
        }
        return cnt;
    }
};
