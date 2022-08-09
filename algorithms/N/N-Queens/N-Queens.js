// time O(n!) | space O(n^n)
var solveNQueens = function(n) {
    let res = [];
    
    function backtrack(board, r) {
        if (r === n) {
            // - 1 to account for adding a Q that takes up a space
            res.push(board.map((c) => '.'.repeat(c) + 'Q' + '.'.repeat(n - c - 1)));
            return;
        }
        
        for (let c = 0; c < n; c++) {
            // bc is the current element
            // br is the index of the element bc
            //
            // bc === c | checks row and col
            // bc === c - r + br | checks lower diagonal
            // bc === c + r - br | checks upper diagonal
            if (!board.some((bc, br) => bc === c || bc === c - r + br || bc === c + r - br)) {
                backtrack(board.concat(c), r + 1);
            }
        }
    }
    
    backtrack([], 0);
    
    return res;
};
