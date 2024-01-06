// Runtime: 375 ms (Top 84.23%) | Memory: 127.40 MB (Top 49.7%)

class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
      int m=grid.size(), n=grid[0].size();
        vector<int> dir={0,1,0,-1,0};
        vector<vector<int>> dist(m, vector<int> (n,INT_MAX));
        vector<vector<bool>> vis(m, vector<bool>(n,0));
        deque<pair<int,int>>q;
        dist[0][0]=0;
        q.push_front({0,0});
        while(!q.empty())
        {
            auto cur=q.front();
            q.pop_front();
            int x=cur.first;
            int y=cur.second;
            for(int i=0;i<4;i++)
            {
                int cx=x+dir[i];
                int cy=y+dir[i+1];
            if(cx>=0 and cy>=0 and cx<m and cy<n)
            {
                if(!vis[cx][cy])
                {
                    dist[cx][cy]=dist[x][y]+(grid[cx][cy]==1);
                    if(grid[cx][cy]==1)
                        q.push_back({cx,cy});//obstacle cell pushed at the end
                    else
                    q.push_front({cx,cy}); //empty cell pushed on top
                    vis[cx][cy] = true;
                }
            }
        }
    }
        return dist[m-1][n-1];
    }
};
