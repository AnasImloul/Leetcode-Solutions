// Runtime: 7 ms (Top 97.22%) | Memory: 8.70 MB (Top 95.14%)

struct node
{
    int x,y;
    node(int xx,int yy)
    {
        x=xx;y=yy;
    }
};

struct node2
{
    int x,y,dir;
    node2(int xx,int yy,int dd)
    {
        x=xx;y=yy;dir=dd;
    }
};

class Solution {
    vector<vector<int>>dfn;
    vector<vector<vector<int>>>color;
    vector<vector<vector<bool>>>cover;
    vector<vector<int>>mi;
    vector<vector<char>>grid;
    int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
    int id;
    int sid;
    vector<vector<bool>>ins;
    stack<node2>st;
    int n,m;
    
    void dfs(int x,int y,int last_dir)
    {
        dfn[x][y]=mi[x][y]=++id;
        int i;

        for(i=0;i<4;i++)
        {
            if((last_dir^1)==i)
            {
                continue;
            }
            int nx,ny;
            nx=x+dir[i][0];
            ny=y+dir[i][1];

            if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny]!='#')
            {
                if(cover[x][y][i]==0 && cover[nx][ny][i^1]==0)
                {
                    st.push(node2(x,y,i));
                    cover[x][y][i]=cover[nx][ny][i^1]=1;
                }
                if(dfn[nx][ny]==0)
                {
                    dfs(nx,ny,i);
                    if(dfn[x][y]<=mi[nx][ny])
                    {
                        node2 now(0,0,0);
                        do
                        {
                            now=st.top();
                            st.pop();
                            color[now.x][now.y][now.dir]=sid;
                            color[now.x+dir[now.dir][0]][now.y+dir[now.dir][1]][now.dir^1]=sid;
                        }while(now.x!=x || now.y!=y || now.dir!=i);
                        sid++;
                    }
                    mi[x][y]=min(mi[x][y],mi[nx][ny]);
                }
                else // if(ins[nx][ny]==1)
                {
                    mi[x][y]=min(mi[x][y],dfn[nx][ny]);
                }
            }
        }
        return;
    }

public:
    int minPushBox(vector<vector<char>>& grid) {
        this->grid=grid;
        n=grid.size();
        m=grid[0].size();
        int i,j,k;
        dfn=vector<vector<int>>(n,vector<int>(m,0));
        color=vector<vector<vector<int>>>(n,vector<vector<int>>(m,vector<int>(4,0)));
        cover=vector<vector<vector<bool>>>(n,vector<vector<bool>>(m,vector<bool>(4,0)));
        mi=vector<vector<int>>(n,vector<int>(m,INT_MAX));
        ins=vector<vector<bool>>(n,vector<bool>(m,0));
        id=0;
        sid=1;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(grid[i][j]!='#' && dfn[i][j]==0)
                {
                    dfs(i,j,-1);
                }
            }
        }

        int sx,sy,ex,ey,bx,by;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(grid[i][j]=='S')
                {
                    sx=i;sy=j;
                }

                if(grid[i][j]=='T')
                {
                    ex=i;ey=j;
                }

                if(grid[i][j]=='B')
                {
                    bx=i;by=j;
                }
            }
        }

        ins=vector<vector<bool>>(n,vector<bool>(m,0));
        queue<node>q;
        queue<node2>q2;
        q.push(node(sx,sy));
        ins[sx][sy]=1;
        int dp[n][m][4];
        memset(dp,-1,sizeof(dp));

        while(!q.empty())
        {
            node now=q.front();
            q.pop();
            for(i=0;i<4;i++)
            {
                int nx,ny;
                nx=now.x+dir[i][0];
                ny=now.y+dir[i][1];
                if(nx>=0 && nx<n && ny>=0 && ny<m)
                {
                    if(nx==bx && ny==by)
                    {
                        dp[bx][by][i^1]=0;
                        q2.push(node2(bx,by,i^1));
                    }
                    else if(grid[nx][ny]!='#' && ins[nx][ny]==0)
                    {
                        ins[nx][ny]=1;
                        q.push(node(nx,ny));
                    }
                }
            }
        }

        while(!q2.empty())
        {
            node2 now=q2.front();
            q2.pop();

            if(now.x==ex && now.y==ey)
            {
                return dp[now.x][now.y][now.dir];
            }
            
            int nx,ny;
            

            for(i=0;i<4;i++)
            {
                if(i==now.dir)
                {
                    continue;
                }

                nx=now.x+dir[i][0];
                ny=now.y+dir[i][1];
                if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny]!='#' && dp[now.x][now.y][i]==-1 && color[now.x][now.y][now.dir]==color[now.x][now.y][i])
                {
                    dp[now.x][now.y][i]=dp[now.x][now.y][now.dir];
                    q2.push(node2(now.x,now.y,i));
                }
            }

            int d=(now.dir^1);
            nx=now.x+dir[d][0];
            ny=now.y+dir[d][1];
            if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny]!='#' && dp[nx][ny][now.dir]==-1)
            {
                dp[nx][ny][now.dir]=dp[now.x][now.y][now.dir]+1;
                q2.push(node2(nx,ny,now.dir));
            }
        }

        return -1;
    }
};
