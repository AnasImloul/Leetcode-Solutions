// Runtime: 192 ms (Top 16.37%) | Memory: 30 MB (Top 73.15%)

class Solution {
   bool isValid(vector<vector<int>>& grid,int r,int c,int nr,int nc,int m,int n){
        if(nr>=0 && nc>=0 && nr<m && nc<n && grid[nr][nc]==-1){
            if(grid[r][c]==0)
                grid[nr][nc]=1;
            else
                grid[nr][nc]=grid[r][c]+1;
            return 1;
        }
        return 0;
    }
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int,int>> q;
        int m = mat.size();
        int n = mat[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0)
                    q.push({i,j});
                else
                    mat[i][j]=-1;
            }
        }
        while(!q.empty()){
            auto per = q.front();
            int r = per.first;
            int c = per.second;
            // if()
            q.pop();
            if(isValid(mat,r,c,r-1,c,m,n)){
                q.push({r-1,c});
            }
            if(isValid(mat,r,c,r+1,c,m,n)){
                q.push({r+1,c});
            }
            if(isValid(mat,r,c,r,c-1,m,n)){
                q.push({r,c-1});
            }
            if(isValid(mat,r,c,r,c+1,m,n)){
                q.push({r,c+1});
            }

        }
        return mat;
    }
};