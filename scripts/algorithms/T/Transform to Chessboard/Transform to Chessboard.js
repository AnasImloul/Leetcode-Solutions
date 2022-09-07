// Runtime: 100 ms (Top 33.33%) | Memory: 44.3 MB (Top 33.33%)
/**
 * @param {number[][]} board
 * @return {number}
 */
var movesToChessboard = function(board) {
    const boardSize = board.length;
    const boardSizeIsEven = boardSize % 2 === 0;

    if(!canBeTransformed(board)) return -1;

    // to convert to 010101
    let rowSwap = 0;
    let colSwap = 0;

    // to convert to 101010
    let rowSwap2 = 0;
    let colSwap2 = 0;

    for(let i=0; i<boardSize; i++) {
        if(board[i][0] === i % 2) {
            rowSwap++;
        } else {
            rowSwap2++;
        }
        if(board[0][i] === i % 2) {
            colSwap++;
        } else {
            colSwap2++;
        }
    }

    // no need to swap anything
    if((rowSwap + colSwap) === 0 || (rowSwap2 + colSwap2) === 0) return 0;

    if(boardSizeIsEven) {
        rowSwap = Math.min(rowSwap, rowSwap2);
        colSwap = Math.min(colSwap, colSwap2);
    } else {
        rowSwap = rowSwap % 2 === 0 ? rowSwap : rowSwap2;
        colSwap = colSwap % 2 === 0 ? colSwap : colSwap2;
    }

    return (rowSwap + colSwap) / 2;

    function canBeTransformed(board) {
        // number of 0 and 1 should be equal
        let sum = board[0].reduce((a,b) => a+b);
        if(boardSizeIsEven && sum != boardSize/2) return false;
        if(!boardSizeIsEven && sum > ((boardSize + 1)/2)) return false;

        let first = board[0].join('');
        let opposite = board[0].map((item) => item === 1 ? 0 : 1).join('');
        // each row should be equal to first or opposite
        let counter = [0,0];
        for(let i=0; i<boardSize; i++) {
            let str = board[i].join('');
            if(str == first) {
                counter[0]++;
            } else if(str == opposite) {
                counter[1]++;
            } else {
                return false;
            }
        }
        // for even board, two types of rows should be equal
        if(boardSizeIsEven) {
            return counter[0] == counter[1];
        }
        return Math.abs(counter[0] - counter[1]) === 1
    }
};