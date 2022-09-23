// Runtime: 77 ms (Top 87.47%) | Memory: 20.3 MB (Top 91.20%)
class Solution {
public:
    int maximumMinutes(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> firetime(m, vector<int>(n, INT_MAX));
        queue<pair<int, int>> q;
        // push fire positions into queue, and set the time as 0
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1){
                    q.push(make_pair(i, j));
                    firetime[i][j] = 0;
                }
            }
        }
        int time = 0;
        pair<int, int> xy;
        int x,y;
        // use BFS to find fire spread time
        while(!q.empty()){
            int points = q.size();
            time++;
            for(int i=0; i<points; i++){
                xy = q.front();
                q.pop();
                x = xy.first, y = xy.second;
                if(x-1>=0 && grid[x-1][y]==0 && firetime[x-1][y]==INT_MAX){
                    q.push(make_pair(x-1, y));
                    firetime[x-1][y] = time;
                }
                if(x+1<m && grid[x+1][y]==0 && firetime[x+1][y]==INT_MAX){
                    q.push(make_pair(x+1, y));
                    firetime[x+1][y] = time;
                }
                if(y-1>=0 && grid[x][y-1]==0 && firetime[x][y-1]==INT_MAX){
                    q.push(make_pair(x, y-1));
                    firetime[x][y-1] = time;
                }
                if(y+1<n && grid[x][y+1]==0 && firetime[x][y+1]==INT_MAX){
                    q.push(make_pair(x, y+1));
                    firetime[x][y+1] = time;
                }
            }
        }
        vector<vector<int>> peopletime(m, vector<int>(n, INT_MAX));
        time = 0;
        // push the initial position of the top left cell into the queue
        // and set the time as 0
        q.push(make_pair(0, 0));
        peopletime[0][0] = 0;
        // use BFS to find the traversal time
        while(!q.empty()){
            int points = q.size();
            time++;
            for(int i=0; i<points; i++){
                xy = q.front();
                q.pop();
                x = xy.first, y = xy.second;
                if(x-1>=0 && grid[x-1][y]==0 && peopletime[x-1][y]==INT_MAX && firetime[x-1][y]>time){
                    q.push(make_pair(x-1, y));
                    peopletime[x-1][y] = time;
                }
                if(x+1<m && grid[x+1][y]==0 && peopletime[x+1][y]==INT_MAX && firetime[x+1][y]>time){
                    q.push(make_pair(x+1, y));
                    peopletime[x+1][y] = time;
                }
                if(y-1>=0 && grid[x][y-1]==0 && peopletime[x][y-1]==INT_MAX && firetime[x][y-1]>time){
                    q.push(make_pair(x, y-1));
                    peopletime[x][y-1] = time;
                }
                if(y+1<n && grid[x][y+1]==0 && peopletime[x][y+1]==INT_MAX && firetime[x][y+1]>time){
                    q.push(make_pair(x, y+1));
                    peopletime[x][y+1] = time;
                }
                if(((x==m-2 && y==n-1) || (x==m-1 && y==n-2))&&(firetime[m-1][n-1]<=time)){
                    q.push(make_pair(m-1, n-1));
                    peopletime[m-1][n-1] = time;
                }
            }
        }
        // if you cannot reach the safehouse or fire reaches the safehouse first,
        // return -1
        if(peopletime[m-1][n-1]==INT_MAX || firetime[m-1][n-1]<peopletime[m-1][n-1]){
            return -1;
        }
        // if fire can never reach the safehouse,
        // return 1000000000
        if(firetime[m-1][n-1]==INT_MAX){
            return 1000000000;
        }
        if(firetime[m-1][n-1]==peopletime[m-1][n-1]){
            return 0;
        }
        int diff = (firetime[m-1][n-1]-peopletime[m-1][n-1]);
        if(m>1 && n>1){
            if(peopletime[m-2][n-1]!=INT_MAX && peopletime[m-1][n-2]!=INT_MAX && ((firetime[m-2][n-1]-peopletime[m-2][n-1])>diff || (firetime[m-1][n-2]-peopletime[m-1][n-2]>diff))){
                return diff;
            }
        }
        return diff-1;
    }
};