// Runtime: 169 ms (Top 64.28%) | Memory: 49.7 MB (Top 82.47%)
/**
 * @param {number[][]} grid
 * @return {number}
 */
const DIR = [
    [0,1],
    [0,-1],
    [1,0],
    [-1,0]
];

var shortestBridge = function(grid) {
    const que = [];
    const ROWS = grid.length;
    const COLS = grid[0].length;

    // find first insland
    outer:
    for(let row=0; row<ROWS; row++) {
        for(let col=0; col<COLS; col++) {
            if(grid[row][col] == 1) {
                const stack = [[row, col]];
                while(stack.length) {
                    const [r, c] = stack.pop();
                    que.push([r, c]);
                    grid[r][c] = 2; // mark as visited.
                    for(const dir of DIR) {
                        const newRow = r+dir[0];
                        const newCol = c+dir[1];
                        if(newRow<0 || newCol<0 || newRow>=ROWS || newCol>=COLS) continue;
                        if(grid[newRow][newCol] != 1) continue;
                        stack.push([newRow, newCol]);
                    }
                }
                break outer;
            }
        }
    }
    let steps = 0;
    while(que.length) {
        let size = que.length;
        for(let i=0; i<size; i++) {
            const [row, col] = que.shift();
            for(const dir of DIR) {
                const newRow = row+dir[0];
                const newCol = col+dir[1];
                if(newRow<0 || newCol<0 || newRow>=ROWS || newCol>=COLS) continue;
                if(grid[newRow][newCol] == 2) continue;
                if(grid[newRow][newCol] == 1) return steps;
                grid[newRow][newCol] = 2; // mark as visited.
                que.push([newRow, newCol]);
            }
        }
        steps++;
    }
    return -1;
};