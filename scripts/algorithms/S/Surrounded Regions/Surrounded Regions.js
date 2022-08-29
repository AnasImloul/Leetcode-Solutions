// Runtime: 139 ms (Top 46.98%) | Memory: 46.3 MB (Top 81.77%)
// time O(n * m) | space O(1)

// We essentially invert this question
// Instead of looking whether an 'O' node is surrounded,
// we check if an 'O' node is on the edge (outer layer can't be surrounded)
// and check if that is connected with any other nodes 'O' nodes (top, down, left, right).
// We do no care if it is not connected to an 'O' edge node and thus never dfs for it.
var solve = function(board) {
    if (!board.length) return [];

    for (let i = 0; i < board.length; i++) {
        for (let j = 0; j < board[0].length; j++) {
            // Only dfs if an 'O' and on the edge
            if (board[i][j] === 'O' && (i === 0 || i === board.length - 1 || j === 0 || j === board[0].length - 1)) {
                dfs(i, j);
            }
        }
    }

    for (let i = 0; i < board.length; i++) {
        for (let j = 0; j < board[0].length; j++) {
            if (board[i][j] === 'V') {
                board[i][j] = 'O';
            } else {
                board[i][j] = 'X';
            }
        }
    }

    return board;

    function dfs(r, c) {
        if (r < 0 || r >= board.length || c < 0 || c >= board[0].length || board[r][c] === 'X' || board[r][c] === 'V') {
            return;
        }

        board[r][c] = 'V';

        dfs(r + 1, c);
        dfs(r - 1, c);
        dfs(r, c - 1);
        dfs(r, c + 1);
    }
};