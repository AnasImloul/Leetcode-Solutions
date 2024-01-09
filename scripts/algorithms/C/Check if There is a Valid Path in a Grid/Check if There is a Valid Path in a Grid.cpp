// Runtime: 116 ms (Top 86.9%) | Memory: 64.20 MB (Top 40.0%)

class Solution {
    int n,m;
    bool vis[305][305];
    vector<vector<int>>g;
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        g = grid;
        memset(vis, false, sizeof(vis));
        dfs(0,0);
        return vis[n-1][m-1];
    }

    void dfs(int ux, int uy){
        vis[ux][uy]=true;
        int vx,vy;

        if(g[ux][uy] == 1 || g[ux][uy]==4 || g[ux][uy]==6) {vx=ux, vy=uy+1; if(valid(vx, vy) && L_enter(vx,vy)) dfs(vx, vy);}
        if(g[ux][uy] == 1 || g[ux][uy]==3 || g[ux][uy]==5) {vx=ux, vy=uy-1; if(valid(vx, vy) && R_enter(vx,vy)) dfs(vx, vy);}
        if(g[ux][uy] == 2 || g[ux][uy]==3 || g[ux][uy]==4) {vx=ux+1, vy=uy; if(valid(vx, vy) && D_enter(vx,vy)) dfs(vx, vy);}
        if(g[ux][uy] == 2 || g[ux][uy]==5 || g[ux][uy]==6) {vx=ux-1, vy=uy; if(valid(vx, vy) && U_enter(vx,vy)) dfs(vx, vy);} 

    }
    bool valid(int x , int y){
        if(x>=0 && y>=0 && x<n && y<m && !vis[x][y] ) return true;
        return false;
    }
    bool L_enter(int x, int y){
        if(g[x][y]%2) return true;
        return false;
    }
    bool R_enter(int x, int y){
        if(g[x][y]==1 || g[x][y]==4 || g[x][y]==6) return true;
        return false;
    }
    bool D_enter(int x, int y)
    {
        if(g[x][y]==2 || g[x][y]==5 || g[x][y]==6) return true;
        return false;
    }
     bool U_enter(int x, int y)
    {
        if(g[x][y]==2 || g[x][y]==3 || g[x][y]==4) return true;
        return false;
    }
};
