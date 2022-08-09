/**
 * @param {number[][]} moves
 * @return {string}
 */
let validate = (arr) => {
    let set = [...new Set(arr)];
    return set.length == 1 && set[0] != 0;
}

var tictactoe = function(moves) {
    let grid = [[0,0,0],[0,0,0],[0,0,0]];
    for(let i in moves){
        let [x,y] = moves[i]
        grid[x][y] = (i % 2 == 1) ? -1 : 1;
        if(validate(grid[x]) 
           || validate(grid.reduce((prev, curr) => [...prev, curr[y]], []))
           || validate([grid[0][0], grid[1][1], grid[2][2]])
           || validate([grid[0][2], grid[1][1], grid[2][0]])
          )
            return (i % 2) ? "B" : "A";
    }
    return (moves.length == 9) ? "Draw" : "Pending"
};