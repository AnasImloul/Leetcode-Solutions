var findMinStep = function(board, hand) { 
    var map = {};
    var recursion = function (board, hand) {
        if (board.length === 0) return 0;
        // Check map
        var key = board + '-' + hand;
        if (map[key]) return map[key];

        var res = hand.length + 1;
        var set = new Set();
        for (var i = 0; i < hand.length; i++) {
            if (set.has(hand[i])) continue;
            for (var j = 0; j < board.length; j++) {
                // Board: ..WW.., Hand: ..(W).. => W(W)W === WW(W)
                if (j < board.length - 1 && board[j] === board[j + 1] && hand[i] === board[j]) continue;
                var newBoard = board.slice(0, j + 1) + hand[i] + board.slice(j + 1);
                var newHand = hand.slice(0, i) + hand.slice(i + 1);
                res = Math.min(res, recursion(reduceBoard(newBoard), newHand) + 1);
            }
            set.add(hand[i]);
        }
        // Save to map
        map[key] = res;
        return res;
    }
    
    var result = recursion(board, hand);
    return result > hand.length ? -1 : result;
};

var reduceBoard = function(board) {
    var str = '';
    for (var i = 0; i < board.length; i++) {
        // Check group of 3 or more balls in the same color touching
        if (i < board.length - 2 && board[i] === board[i + 1] && board[i + 1] === board[i + 2]) {
            var start = i;
            i += 2;
            while (board[i] === board[i + 1]) i++;
            // Reduce, e.g.RBBBRR
            return reduceBoard(board.slice(0, start) + board.slice(i + 1));
        }
        else {
            str += board[i];
        }
    }
    return str;
}
