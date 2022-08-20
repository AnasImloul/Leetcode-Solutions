// Runtime: 123 ms (Top 42.01%) | Memory: 21.4 MB (Top 49.39%)

class Solution {
public:
    int dx[4]={0,0,-1,1};
    int dy[4]={1,-1,0,0};
    int maxDistance(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> dis(n,vector<int>(m,INT_MAX));
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                if(grid[i][j]==1)
                {
                    q.push({i,j});
                    dis[i][j]=0;
                }
            }
        }
        while(!q.empty())
        {
            auto temp=q.front();
            q.pop();
            int x=temp.first;
            int y=temp.second;
            for(int i=0;i<4;++i)
            {
                int nx=x+dx[i];
                int ny=y+dy[i];
                int ndis=dis[x][y]+1;
                if(nx>=0 && ny>=0 && nx<n && ny<m && ndis<dis[nx][ny])
                {
                    q.push({nx,ny});
                    dis[nx][ny]=ndis;
                }
            }
        }
        int ans=-1;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                if(grid[i][j]!=1)
                {
                    ans=max(ans,dis[i][j]);
                }
            }
        }
        return (ans!=INT_MAX)?ans:-1; // if ans==INT_MAX then there are only wate(no land)
    }
};