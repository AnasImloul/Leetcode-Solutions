// Runtime: 251 ms (Top 38.18%) | Memory: 58.2 MB (Top 43.64%)
/**
 * @param {character[][]} board
 * @param {string} word
 * @return {boolean}
 */
var placeWordInCrossword = function(board, word) {
    for (let i = 0; i < board.length; i++) {
        for (let j = 0; j < board[0].length; j++) {
            if (i === 0 || board[i - 1][j] === '#') {
                if (match(getFill(i, j, false))) {
                    return true;
                }
            }
            if (j === 0 || board[i][j - 1] === '#') {
                if (match(getFill(i, j, true))) {
                    return true;
                }
            }
        }
    }
    return false;

    function getFill(x, y, goRight) {
        if (x >= 0 && x < board.length && y >= 0 && y < board[0].length && board[x][y] !== '#') {
            return goRight ? board[x][y] + getFill(x, y + 1, goRight) : board[x][y] + getFill(x + 1, y, goRight);
        }
        return '';
    }

    function match(str) {
        if (str.length !== word.length) {
            return false;
        }
        let fromLeft = true;
        let fromRight = true;
        let l = 0;
        let r = str.length - 1;
        for (let each of word) {
            if (!fromLeft && !fromRight) {
                return false;
            }
            if (fromLeft) {
                if (each !== str[l] && str[l] !== ' ') {
                    fromLeft = false;
                }
                l++;
            }
            if (fromRight) {
                if (each !== str[r] && str[r] !== ' ') {
                    fromRight = false;
                }
                r--;
            }
        }
        return fromLeft || fromRight;
    }
};