var maxProductPath = function(grid) {
    const R = grid.length, C = grid[0].length;
    if (R === 0 || C === 0)
        return -1;
    
    const mat = [...Array(R)].map(() => [...Array(C)].map(() => new Array(2)));
    
    mat[0][0] = [grid[0][0], grid[0][0]];
    for (let i = 1; i < R; i++)
        mat[i][0] = [mat[i-1][0][0]*grid[i][0], mat[i-1][0][1]*grid[i][0]];
    
    for (let i = 1; i < C; i++)
        mat[0][i] = [mat[0][i-1][0]*grid[0][i], mat[0][i-1][1]*grid[0][i]];
    
    for (let i = 1; i < R; i++) {
        for (let j = 1; j < C; j++) {
            const max = Math.max(mat[i-1][j][0], mat[i][j-1][0]),
                  min = Math.min(mat[i-1][j][1], mat[i][j-1][1]);
            if (grid[i][j] >= 0)
                mat[i][j] = [max*grid[i][j], min*grid[i][j]];
            else
                mat[i][j] = [min*grid[i][j], max*grid[i][j]];
        }
    }
    
    return mat[R-1][C-1][0] >= 0 ? mat[R-1][C-1][0] % (10**9+7) : -1;
};
