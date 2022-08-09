class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size(),n = grid[0].size();
        if(grid[0][0]!=0 || grid[m-1][n-1]!=0) return -1;
        vector<vector<int>> dist(m,vector<int>(n,INT_MAX));
        int ans = INT_MAX;
        queue<pair<int,int>> q;
        dist[0][0]=1;
        q.push({0,0});
        
        int dir[8][2] = {{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1}};
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            for(int i = 0;i<8;i++){
                int newi = curr.first + dir[i][0];
                int newj = curr.second + dir[i][1];
                if(newi>=0 && newi<m && newj>=0 && newj<n && grid[newi][newj]==0){
                    if(dist[newi][newj]>dist[curr.first][curr.second]+1){
                        dist[newi][newj] = dist[curr.first][curr.second]+1;
                        q.push({newi,newj});
                    }
                }
            }
        }
            
        return dist[m-1][n-1]==INT_MAX?-1:dist[m-1][n-1]; 
    }
};
