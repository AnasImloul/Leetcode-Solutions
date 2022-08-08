var colorBorder = function(grid, row, col, color) {
    const m = grid.length;
    const n = grid[0].length;
    const dirs = [-1, 0, 1, 0, -1];

    const res = [];

    for (let i = 0; i < m; i++) {
        res[i] = new Array(n).fill(-1);
    }

    const val = grid[row][col];

    const stack = [];
    const visited = new Set();

    visited.add(`${row}#${col}`); 
    stack.push([row, col]);

    while (stack.length > 0) {
        const [currRow, currCol] = stack.pop();

        let isConnected = true;

        for (let i = 0; i < dirs.length - 1; i++) {
            const neiRow = currRow + dirs[i];
            const neiCol = currCol + dirs[i + 1];

            if (withinBound(neiRow, neiCol)) {
                if (!visited.has(`${neiRow}#${neiCol}`)) {
                    if (grid[neiRow][neiCol] === val) {
                        visited.add(`${neiRow}#${neiCol}`);
                        stack.push([neiRow, neiCol]);
                    }
                    else {
                        isConnected = false;
                    }
                }
            }
        }

        if (isBorder(currRow, currCol) || !isConnected) res[currRow][currCol] = color;
    }

    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (res[i][j] === -1) {
                res[i][j] = grid[i][j];
            }
        }
    }

    return res;


    function withinBound(row, col) {
        return row >= 0 && col >= 0 && row < m && col < n;
    }

    function isBorder(row, col) {
        return row === 0 || col === 0 || row === m - 1 || col === n - 1;
    }
};
