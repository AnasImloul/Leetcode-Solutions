// Runtime: 172 ms (Top 37.35%) | Memory: 51.6 MB (Top 7.23%)
/**
 * @param {number[][]} board
 * @return {number}
 */

class BoardState {
    constructor(board, currStep) {
        this.board = this.copyBoard(board);
        this.boardString = this.flatToString(board);
        this.emptyIndex = this.findIndexOf0(board);
        this.currStep = currStep;
    }
    findIndexOf0(board) {
        for(let i = 0; i < board.length; i++) {
            for (let j = 0; j < board[i].length; j++) {
                if(board[i][j] === 0) return [i, j];
            }
        }
        return null;
    }
    copyBoard(board) {
        const newBoard = [];
        board.forEach((row) => {
             newBoard.push([...row]);
        });
        return newBoard;
    }
    flatToString(board) {
        let str = '';
        for(let i = 0; i < board.length; i++) {
            for (let j = 0; j < board[i].length; j++) {
                str += board[i][j];
            }
        }
        return str;
    }
}
var slidingPuzzle = function(board) {
    let queue = [new BoardState(board, 0)];
    let set = new Set();
    const x = board.length, y = board[0].length;
    const switchMoves = [[1, 0], [0, 1], [-1, 0], [0, -1]];
    let slide = (i, j, newi, newj, currBoardState) => {
        if (newi < 0 || newj < 0 || newi >= x || newj >= y) {
            return null;
        }
        const newBoard = currBoardState.copyBoard(currBoardState.board);
        const temp = newBoard[i][j];
        newBoard[i][j] = newBoard[newi][newj];
        newBoard[newi][newj] = temp;
        const newBoardState = new BoardState(newBoard, currBoardState.currStep + 1);
        return newBoardState
    }
    while(queue.length > 0) {
        const currBoardState = queue.shift();
        set.add(currBoardState.boardString);
        if(currBoardState.boardString === '123450') {
            return currBoardState.currStep;
        }
        const [i, j] = currBoardState.emptyIndex;
        switchMoves.forEach((move) => {
            const newBoardState = slide(i, j, i + move[0], j + move[1], currBoardState);
            if (newBoardState && !set.has(newBoardState.boardString)) {
                queue.push(newBoardState);
            }
        });
    }
    return -1;
};