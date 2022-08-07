class Solution {
public:
    int memo[200][200];

    int util(vector<vector<int>>& matrix, vector<vector<bool>>& visited, int i, int j, int prev) {
        if(memo[i][j]) return memo[i][j];

        int temp=0;
        if(i>0) {
            if(matrix[i-1][j]>prev && !visited[i-1][j]) {
                visited[i-1][j]=true;
                temp=max(temp, 1+util(matrix, visited, i-1, j, matrix[i-1][j]));
                visited[i-1][j]=false;
            }
        }
        if(i<matrix.size()-1) {
            if(matrix[i+1][j]>prev && !visited[i+1][j]) {
                visited[i+1][j]=true;
                temp=max(temp, 1+util(matrix, visited, i+1, j, matrix[i+1][j]));
                visited[i+1][j]=false;
            }
        }
        if(j>0) {
            if(matrix[i][j-1]>prev && !visited[i][j-1]) {
                visited[i][j-1]=true;
                temp=max(temp, 1+util(matrix, visited, i, j-1, matrix[i][j-1]));
                visited[i][j-1]=false;
            }
        }
        if(j<matrix[0].size()-1) {
            if(matrix[i][j+1]>prev && !visited[i][j+1]) {
                visited[i][j+1]=true;
                temp=max(temp, 1+util(matrix, visited, i, j+1, matrix[i][j+1]));
                visited[i][j+1]=false;
            }
        }

        return memo[i][j]=temp;
    } 
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m=matrix.size(), n=matrix[0].size();
        
        int ans=0;
        
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                visited[i][j]=true;
                ans=max(ans, 1+util(matrix, visited, i, j, matrix[i][j]));
                visited[i][j]=false;
            }
        }
        
        return ans;
    }
};
