// Runtime: 227 ms (Top 76.47%) | Memory: 98.70 MB (Top 70.59%)

const dirs = [[-1,0],[1,0],[0,-1],[0,1]];

var containsCycle = function(grid) {
    const n=grid.length, m=grid[0].length;
    const dfs = function(type, i, j, previ, prevj){
        if(i<0 || j<0 || i==n || j==m) return false;
        if(grid[i][j]!=type) return grid[i][j]==type.toUpperCase();
        grid[i][j]=grid[i][j].toUpperCase();
        for(let dir of dirs){
            if(i+dir[0]==previ && j+dir[1]==prevj) continue;
            if(dfs(type,i+dir[0],j+dir[1],i,j)) return true;
        }
        return false;
    }
    
    for(let i=0; i<n; i++)
        for(let j=0; j<m; j++){
            if(grid[i][j]==grid[i][j].toUpperCase()) continue;
            if(dfs(grid[i][j], i, j, -1, -1)) return true;
        }
    return false;
};

