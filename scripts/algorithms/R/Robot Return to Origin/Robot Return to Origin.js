// Runtime: 111 ms (Top 44.23%) | Memory: 43.1 MB (Top 76.28%)
var judgeCircle = function(moves) {
    let x=0,y=0
    for(i=0;i<moves.length;i++){
        switch (moves[i]) {
            case 'R':
                x++;
                break;
            case 'L':
                x--;
                break;
            case 'U':
                y++;
                break;
            case 'D':
                y--;
                break;
        }
    }
     return x === 0 && y === 0

};