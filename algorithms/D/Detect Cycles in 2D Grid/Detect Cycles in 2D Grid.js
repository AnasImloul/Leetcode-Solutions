/**
 * @param {character[][]} grid
 * @return {boolean}
 */
var containsCycle = function(grid) {
    const m = grid.length;
    const n = grid[0].length;
    const visited = [...Array(m)].map(i => Array(n).fill(0));
    const dir = [[-1,0],[1,0],[0,-1],[0,1]];
    
    const dfs = (x,y,lx,ly) => {        
        visited[x][y] = 1;
        for (const [a, b] of dir) {
            const nx = x + a;
            const ny = y + b;
            
            if (nx < 0 || nx > m - 1 || ny < 0 || ny > n - 1)
                continue;
            
            if (visited[nx][ny] === 1 && (nx !== lx || ny !== ly) && grid[x][y] === grid[nx][ny]) { // !!! grid[nx][ny] === grid[x][y]
                return true;
            }
            
            if (visited[nx][ny] === 0 && grid[x][y] === grid[nx][ny]) {
                if (dfs(nx,ny,x,y))
                    return true;
            }
        }
        return false;
    }
    
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (visited[i][j] === 0 && dfs(i,j,-1,-1)) // !!!
                return true;
        }
    }
    
    return false;
};
