// Runtime: 263 ms (Top 33.64%) | Memory: 50 MB (Top 56.36%)
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
var maxDistance = function(grid) {
    const ROWS = grid.length;
    const COLS = grid[0].length;
    const cost = new Array(ROWS).fill().map(()=>new Array(COLS).fill(Infinity));
    const que = [];
    for(let row=0; row<ROWS; row++) {
        for(let col=0; col<COLS; col++) {
            if(grid[row][col] === 1) {
                que.push([row, col]);
                cost[row][col] = 0;
            }
        }
    }
    if(que.length == 0 || que.length == ROWS * COLS) return -1;
    while(que.length) {
        const [row, col] = que.shift();
        for(const dir of DIR) {
            const newRow = row+dir[0];
            const newCol = col+dir[1];
            if(newRow < 0 || newCol < 0 || newRow >= ROWS || newCol >= COLS) continue;
            if(cost[newRow][newCol] > cost[row][col] + 1) {
                cost[newRow][newCol] = cost[row][col] + 1;
                que.push([newRow, newCol]);
            }
        }
    }
    let max = 0;
    for(const row of cost) {
        max = Math.max(max, ...row);
    }
    return max;
};