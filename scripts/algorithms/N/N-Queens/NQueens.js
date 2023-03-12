var solveNQueens = function(n) {
    const board = new Array(n).fill().map(() => new Array(n).fill('.'));

    const result = [];
    const pushToResult = () =>
        result.push(board.map((row) => row.reduce((acc, val) => acc + val, '')));

    const isQueenPlaced = (i, j) => {
        if(i < 0 || j < 0) return false;
        if(i >= n || j >= n) return false;
        return board[i][j] !== '.';
    };
    const isAttacked = (i, j) => {
        const isSameDiagonalLeft = () => {
            let p = i;
            let q = j;
            while(p >= 0 && q >= 0) {
                if(isQueenPlaced(p, q)) return true;
                p -= 1;
                q -= 1;
            }
            return false;
        };
        const isSameDiagonalRight = () => {
            let p = i;
            let q = j;
            while(p >= 0 && q < n) {
                if(isQueenPlaced(p, q)) return true;
                p -= 1;
                q += 1;
            }
            return false;
        };

        return isSameDiagonalLeft() || isSameDiagonalRight();
    }

    let rowsPlaced = {};
    let colPlaced = {};
    const backtrack = (i = 0, j = 0, queensPlaced = 0) => {
        if(queensPlaced === n) return pushToResult();
        if(i >= n || j >= n) return;
        if(rowsPlaced[i]) return;
        if(colPlaced[j]) return backtrack(i, j + 1, queensPlaced);

        if(!isAttacked(i, j)) {
            rowsPlaced[i] = true;
            colPlaced[j] = true;
            board[i][j] = 'Q';
            backtrack(i + 1, 0, queensPlaced + 1);
            board[i][j] = '.';
            colPlaced[j] = false;
            rowsPlaced[i] = false;
        }

        return backtrack(i, j + 1, queensPlaced);
    }
    backtrack();

    return result;
};