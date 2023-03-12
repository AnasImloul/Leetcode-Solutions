class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        int n = (int)grid.size();
        int m = (int)grid[0].size();

        if (grid[1][0] > 1 && grid[0][1] > 1) {
            return -1;  
        }

        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};

        priority_queue<pair<int, pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq; // time : x : y

        int time[n][m];
        for(int i = 0; i < n; ++i){
            for(int j =0; j < m; ++j){
                time[i][j] = (int)1e9;
            }
        }        

        pq.push({0,{0,0}});
        time[0][0] = 0;
        while(!pq.empty()){
            int curtime = pq.top().first;
            int curx = pq.top().second.first;
            int cury = pq.top().second.second;
            pq.pop();
            if(curtime > time[curx][cury]){
                continue;  
            }
            if(curx == n - 1 && cury == m - 1){
                return curtime;
            }
            for(int i = 0; i < 4 ; ++i){
                int newtime = curtime + 1;
                int nx = curx + dx[i];
                int ny = cury + dy[i];
                if(nx < 0 || nx >= n || ny < 0 || ny >=m){
                    continue;
                }
                if (grid[nx][ny] > newtime) {
                    int diff = grid[nx][ny] - newtime;
                    if (diff & 1) {
                        ++diff;
                    }
                    newtime = newtime + diff;
                }
                if(newtime < time[nx][ny]){
                    time[nx][ny] = newtime;
                    pq.push({newtime, {nx, ny}});
                }
            }
        }
        return -1;
    }
};