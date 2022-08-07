/**
 * @param {character[][]} board
 * @return {boolean}
 */
var isValidSudoku = function(board) {
    let rowMap = new Map();
    let colMap = new Map();
    let square = new Map();
    for(let i=0; i<board.length; i++) {
        for(let j=0; j<board[0].length; j++) {
            if(board[i][j] === '.') continue;
            if(!rowMap.has(i)) rowMap.set(i, new Set());
            if(!colMap.has(j)) colMap.set(j, new Set());
            let squareKey = Math.floor(i/3) + '#' + Math.floor(j/3);
            if(!square.has(squareKey)) square.set(squareKey, new Set());
            let rowSet = rowMap.get(i);
            let colSet = colMap.get(j);
            let squareSet = square.get(squareKey);
            if(rowSet.has(board[i][j]) || colSet.has(board[i][j]) || squareSet.has(board[i][j])) return false;
            rowSet.add(board[i][j]);
            colSet.add(board[i][j]);
            squareSet.add(board[i][j]);
            rowMap.set(i, rowSet);
            colMap.set(j, colSet);
            square.set(squareKey, squareSet);
        }
    }
    return true;
};
