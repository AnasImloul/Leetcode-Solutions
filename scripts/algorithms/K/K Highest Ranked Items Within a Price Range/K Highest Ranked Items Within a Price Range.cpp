// Runtime: 729 ms (Top 97.18%) | Memory: 174.3 MB (Top 85.68%)

class Solution {
public:
    struct cell
    {
        int dist;
        int cost;
        int row;
        int col;
    };
    struct compare
    {
        bool operator()(const cell &a, const cell &b)
        {
            if(a.dist != b.dist)
                return a.dist < b.dist;
            else if(a.cost != b.cost)
                return a.cost < b.cost;
            else if(a.row != b.row)
                return a.row < b.row;
            else
                return a.col < b.col;
        }
    };

    vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& pricing, vector<int>& start, int k) {
        int m=grid.size();
        int n=grid[0].size();

        queue<pair<int,int>>q;
        q.push({start[0],start[1]});

        vector<vector<bool>> vis(m,vector<bool>(n,false));
        vis[start[0]][start[1]]=true;

        int dx[4]={-1,0,1,0};
        int dy[4]={0,-1,0,1};
        int dist=0;

        priority_queue<cell,vector<cell>,compare> pq;
         while(!q.empty())
         {
             int size=q.size();
             while(size--)
             {
                 pair<int,int> p=q.front(); q.pop();
                 if(grid[p.first][p.second]!=1 && grid[p.first][p.second]>=pricing[0] && grid[p.first][p.second]<=pricing[1])
                 {
                     pq.push({dist,grid[p.first][p.second],p.first,p.second});

                     if(pq.size()>k)
                         pq.pop();
                }
                for(int k=0;k<4;k++)
                {
                    int x=p.first+dx[k];
                    int y=p.second+dy[k];

                    if(x>=0 && x<m && y>=0 && y<n && vis[x][y]==false && grid[x][y]!=0)
                    {
                        vis[x][y]=true;
                        q.push({x,y});
                    }
                }
            }
        dist++;
        }

        vector<vector<int>> ans;
        while(!pq.empty())
        {
        ans.push_back({pq.top().row,pq.top().col});
        pq.pop();
        }

    reverse(ans.begin(),ans.end());
    return ans;
    }
};