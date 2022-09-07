// Runtime: 58 ms (Top 69.42%) | Memory: 12.5 MB (Top 64.22%)
class Solution {
    int dirx[4] = {-1,1,0,0};
    int diry[4] = {0,0,1,-1};
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> matrix(n, vector<int>(m));
        vector<int> lock(7,0);
        int sx, sy;
        int lk = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == '@')
                {
                    sx = i, sy = j;
                    matrix[i][j] = 0;
                }
                else if(grid[i][j] == '.')
                {
                    matrix[i][j] = 0;
                    //cout << grid[i][j];
                }
                else if(grid[i][j] >= 'A' && grid[i][j] <= 'F')
                {
                    matrix[i][j] = -1*((grid[i][j]-'A') + 1);
                    lock[(grid[i][j]-'A') + 1] = (1 << (grid[i][j]-'A'));
                }
                else if(grid[i][j] == '#')
                    matrix[i][j] = -8;
                else
                {
                    matrix[i][j] = (1 << (grid[i][j]-'a'));
                    lk++;
                }
                //cout << matrix[i][j] << " ";
            }
            //cout << endl;
        }
        int fnl = (1 << lk) - 1;
        //cout << fnl;
        vector<vector<int>> visited(n*m, vector<int>(fnl,1));
        queue<pair<pair<int,int>,int>> q;
        int ans = 0;
        q.push({{sx,sy},0});
        visited[sx*m+sy][0] = 0;
        while(!q.empty())
        {
            ans++;
            int sz = q.size();
            while(sz--)
            {
                int x = q.front().first.first;
                int y = q.front().first.second;
                int bit = q.front().second;
                q.pop();
                for(int i = 0; i < 4; i++)
                {
                    int nxtx = x + dirx[i];
                    int nxty = y + diry[i];
                    if(nxtx >= n || nxtx < 0 || nxty >= m || nxty < 0) continue;
                    if(matrix[nxtx][nxty] == -8) continue;
                    if(visited[nxtx*m+nxty][bit] == 0) continue;
                    if(matrix[nxtx][nxty] < 0)
                    {
                        int lkidx = -1*matrix[nxtx][nxty];
                        if(bit&lock[lkidx])
                        {
                            q.push({{nxtx,nxty},bit});
                            visited[nxtx*m+nxty][bit] = 0;
                        }
                    }
                    else if(matrix[nxtx][nxty] == 0)
                    {
                        q.push({{nxtx,nxty},bit});
                        visited[nxtx*m+nxty][bit] = 0;
                        continue;
                    }
                    else
                    {
                        int fbit = bit | matrix[nxtx][nxty];
                        if(fbit == fnl) return ans;
                        q.push({{nxtx,nxty},fbit});
                        visited[nxtx*m+nxty][fbit] = 0;
                    }
                }
            }
        }
        return -1;
    }
};