// Runtime: 101 ms (Top 32.25%) | Memory: 42 MB (Top 79.17%)
/**
 * @param {number[][]} board
 * @return {void} Do not return anything, modify board in-place instead.
 */
var gameOfLife = function(board) {
    const m = board.length, n = board[0].length;
    let copy = JSON.parse(JSON.stringify(board));

    const getNeighbor = (row, col) => {
        let radius = [-1, 0, 1], count = 0;
        for(let i = 0; i < 3; i++) {
            for(let j = 0; j < 3; j++) {
                if(!(radius[i] == 0 && radius[j] == 0) && copy[row + radius[i]] && copy[row + radius[i]][col + radius[j]]) {
                    let neighbor = copy[row + radius[i]][col + radius[j]];
                    if(neighbor == 1) {
                        count++;
                    }
                }
            }
        }
        return count;
    }

    for(let i = 0; i < m; i++) {
        for(let j = 0; j < n; j++) {
            const count = getNeighbor(i, j);
            if(copy[i][j] == 1) {
                if(count < 2 || count > 3) {
                    board[i][j] = 0;
                }
            } else {
                if(count == 3) {
                    board[i][j] = 1;
                }
            }
        }
    }
};