class Solution {
public:
    int row[4] = {-1,1,0,0};
    int col[4] = {0,0,-1,1};
    int in[31][31] , lw[31][31] , vis[31][31];
    bool artpt = false;
    int time = 0;
    int minDays(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size();
        memset(vis,0,sizeof(vis));
        int bodies = 0 , land = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                  if(grid[i][j]==1) {
                       land++;
                       if(!vis[i][j]) {
                           bodies++;
                           dfs(i,j,-1,-1,grid,n,m);
                       }
                  }
            }
        }
        if(bodies == 0 || bodies>1) return 0;  // no body or more than one body , already disconnected (more than one island)
        else if(artpt || land==1) return 1;  // articulation pt or a single patch of land found , just remove that node!
        else return 2;  // otherwise its a ssc (strongly connected component) remove two nodes , one node each day , hence 2 days !
    }
	// learn about how to find articulation points!
	// https://youtu.be/y8hoABkFbT8
    void dfs(int r,int c,int pr,int pc,vector<vector<int>>&grid,int n,int m) {
          vis[r][c] = true;
          in[r][c] = lw[r][c] = ++time;
          int children = 0;
          for(int d=0; d<4; d++) {
               int R = r + row[d] , C = c + col[d];
               if(R>=0 && R<n && C>=0 && C<m && grid[R][C]) {
                      if(!vis[R][C]) {
                          children++;
                          dfs(R,C,r,c,grid,n,m);
                          lw[r][c] = min(lw[r][c],lw[R][C]);
                          if(in[r][c]<=lw[R][C] && pr!=-1) artpt = true;
                      }else {
                          lw[r][c] = min(lw[r][c],in[R][C]);
                      }
               }
          }
        if(pr == -1 && children>1) artpt = true;
    }
};
