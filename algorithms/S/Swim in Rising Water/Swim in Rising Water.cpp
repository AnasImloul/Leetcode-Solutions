class Solution {
public:
    int dir[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
    bool valid(int x,int y,int n)
    {
        return ((x>=0&&x<n)&&(y>=0&&y<n));
    }
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        int time[n][n];
        bool vis[n][n];
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                time[i][j]=1e9;
                vis[i][j]=false;
            }
        }
        time[0][0]=grid[0][0];
        priority_queue<tuple<int,int,int>> q;
        q.push({-time[0][0],0,0});
        while(!q.empty())
        {
            tuple<int,int,int> node=q.top();
            q.pop();
            int x=get<1>(node),y=get<2>(node);
            if(vis[x][y])continue;
            vis[x][y]=true;
            for(int i=0;i<4;++i)
            {
                int xc=x+dir[i][0],yc=y+dir[i][1];
                if(!valid(xc,yc,n))continue;
                if(time[x][y]<grid[xc][yc])
                {
                    time[xc][yc]=grid[xc][yc];
                    q.push({-time[xc][yc],xc,yc});
                }
                else
                {
                    if(time[xc][yc]>time[x][y])
                    {
                        time[xc][yc]=time[x][y];
                        q.push({-time[xc][yc],xc,yc});
                    }
                }
            }
        }
        return time[n-1][n-1];
    }
};
// Time: O(N*N+N*NLOG(N*N))
// Space: O(N*N)
