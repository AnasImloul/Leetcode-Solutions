class Solution {
public:
    int X[4]= {0,0,-1,1};
    int Y[4] = {-1,1,0,0};
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int n = row;
        int m = col;
        vector<vector<int>> a(n,vector<int>(m,0));
        int x = 0;
        for(auto xt : cells)
        {
            int rr = xt[0];
            int cc = xt[1];
            rr--;
            cc--;
            if(!bfs(a,n,m))
                break;
            a[rr][cc]=1;
            x++;
        }
        if(x==0)
            return x;
        return x-1;
    }    
    bool bfs( vector<vector<int>> a , int n , int m)
    {
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++)
        {
                if(a[0][i]==0)
                {
                    q.push({0,i});
                    a[0][i] = 1;
                }
        }
        
        while(!q.empty())
        {
            int ss = q.size();
            while(ss--)
            {
                pair<int,int>pr = q.front();q.pop();
                int ii = pr.first;
                int jj = pr.second;
                if(ii==n-1)
                    return 1;
                for(int i=0;i<4;i++)
                {
                    int nx = ii + X[i];
                    int ny = jj + Y[i];
                    if(nx>=0 and nx<n and ny>=0 and ny<m and a[nx][ny]==0)
                    {
                        q.push({nx,ny});
                        a[nx][ny]=1;
                    }
                }
            }
        }
        return 0;
    }
};
