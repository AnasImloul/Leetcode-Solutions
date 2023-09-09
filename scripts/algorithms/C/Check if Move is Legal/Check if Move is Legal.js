// Runtime: 45 ms (Top 90.9%) | Memory: 42.05 MB (Top 100.0%)

var checkMove = function(board, rMove, cMove, color) {
    const moves = [-1, 0, 1];
    
    let count = 0;
    
    for (let i = 0; i < 3; ++i) {
        for (let j = 0; j < 3; ++j) {
            if (i === 1 && j === 1) continue;
            
            const rowDir = moves[i];
            const colDir = moves[j];
            
            if (isLegal(rMove, cMove, rowDir, colDir, color, 1)) return true;
        }
    }
    
    return false;
      
    function withinBound(row, col) {
        return row >= 0 && col >= 0 && row < 8 && col < 8;
    }
   
    function isLegal(currRow, currCol, rowDir, colDir, startColor, length) {
        if (!withinBound(currRow, currCol)) return false; // we went passed the boundaries
        if (board[currRow][currCol] === startColor) return length >= 3; // we seen another start color
        if (board[currRow][currCol] === "." && length > 1) return false;

        return isLegal(currRow + rowDir, currCol + colDir, rowDir, colDir, startColor, length + 1);
    }
};