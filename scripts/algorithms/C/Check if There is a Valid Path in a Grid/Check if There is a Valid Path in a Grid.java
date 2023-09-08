// Runtime: 15 ms (Top 82.7%) | Memory: 66.95 MB (Top 46.9%)

class Solution {
    public boolean hasValidPath(int[][] grid) {
        int m=grid.length, n=grid[0].length;
        int[][] visited=new int[m][n];
        return dfs(grid, 0, 0, m, n, visited);
    }
    public boolean dfs(int[][] grid, int i, int j, int m, int n, int[][] visited){
        if(i==m-1 && j==n-1) return true;
        if(i<0 || i>=m || j<0 || j>=n || visited[i][j]==1) return false;
        visited[i][j]=1;
        if(grid[i][j]==1){
            if( (j>0 && (grid[i][j-1]==1 || grid[i][j-1]==4 || grid[i][j-1]==6) && dfs(grid, i, j-1, m, n, visited)) || 
			    (j<n-1 && (grid[i][j+1]==1 || grid[i][j+1]==3 || grid[i][j+1]==5 ) && dfs(grid, i, j+1, m, n, visited) )) return true;
        }else if(grid[i][j]==2){
            if( (i<m-1 && (grid[i+1][j]==2 || grid[i+1][j]==5 || grid[i+1][j]==6) && dfs(grid, i+1, j, m, n, visited)) || 
                (i>0 && (grid[i-1][j]==2 || grid[i-1][j]==3 || grid[i-1][j]==4) && dfs(grid, i-1, j, m, n, visited))) return true;
        }else if(grid[i][j]==3){
            if( (j>0 && (grid[i][j-1]==1 || grid[i][j-1]==4 || grid[i][j-1]==6) && dfs(grid, i, j-1, m, n, visited)) || 
			    (i<m-1 && (grid[i+1][j]==2 || grid[i+1][j]==5 || grid[i+1][j]==6) && dfs(grid, i+1, j, m, n, visited))) return true;
        }else if(grid[i][j]==4){
            if( ((i<m-1 && (grid[i+1][j]==2 || grid[i+1][j]==5 || grid[i+1][j]==6)) && dfs(grid, i+1, j, m, n, visited)) || 
			    (j<n-1 && (grid[i][j+1]==1 || grid[i][j+1]==3 || grid[i][j+1]==5) && dfs(grid, i, j+1, m, n, visited))) return true;
        }else if(grid[i][j]==5){
            if( (j>0 && (grid[i][j-1]==1 || grid[i][j-1]==4 || grid[i][j-1]==6) && dfs(grid, i, j-1, m, n, visited)) || 
			    (i>0 && (grid[i-1][j]==2 || grid[i-1][j]==3 || grid[i-1][j]==4) && dfs(grid, i-1, j, m, n, visited))) return true;
        }else{
            if( (i>0 && (grid[i-1][j]==2 || grid[i-1][j]==3 || grid[i-1][j]==4) && dfs(grid, i-1, j, m, n, visited)) || 
			    (j<n-1 && (grid[i][j+1]==1 || grid[i][j+1]==3 || grid[i][j+1]==5) && dfs(grid, i, j+1, m, n, visited))) return true;
        }
        return false;
    }
}