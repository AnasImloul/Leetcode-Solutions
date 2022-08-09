var solveSudoku = function(board) {
    let intBoard = convertBoardToInteger(board);

    let y = 0, x = 0;

    while (y <= 8){
        x = 0;
        while (x <= 8){
            if (isFreeIndex(board, x, y)){
                intBoard[y][x]++;
                while (!isPossibleValue(intBoard, x, y) && intBoard[y][x] < 10){
                    intBoard[y][x]++;
                };

                if (intBoard[y][x] > 9){
                    intBoard[y][x] = 0;
                    let a = retraceBoard(board, x, y);
                    x = a[0], y = a[1];
                    x--;
                }
            }
            x++;
        }
        y++;
    }
    
    convertIntBoardToString(intBoard, board);
}

var isFreeIndex = function(board, x, y){
    return (board[y][x] == '.');
}

var isPossibleValue = function(intBoard, x, y){
    return (isUniqueInColumn(intBoard, x, y) && isUniqueOnRow(intBoard, x, y) && isUniqueInBox(intBoard, x, y))
}
var isUniqueOnRow = function(intBoard, x, y){
    for (let i = 0;i<9;i++){
        if (intBoard[i][x] == intBoard[y][x] && i != y){
            return false;
        }
    }
    return true;
}
var isUniqueInColumn = function(intBoard, x, y){
    for (let i = 0;i<9;i++){
        if (intBoard[y][i] == intBoard[y][x] && i != x){
            return false;
        }
    }
    return true;
}
var isUniqueInBox = function(intBoard, x, y){
    let startX = x - (x % 3);
    let startY = y - (y % 3);

    for (let i = startX; i < startX+3; i++){
        for (let j = startY; j < startY+3; j++){
            if (intBoard[j][i] == intBoard[y][x] && (i != x || j != y)){
                return false;
            }
        }
    }
    return true;
}

var retraceBoard = function(board, x, y){
    do {
        if (x > 0){
            x--;
        } else {
            x = 8;
            y--;
        }
    } while (board[y][x] != '.');
    return [x,y]; 
}

var convertBoardToInteger = function(board){

    let intBoard = new Array(8);
    for (let y = 0;y<9;y++){
        intBoard[y] = new Array(8);
        for (let x =  0;x < 9;x++){
                intBoard[y][x] = parseInt(board[y][x]);
                if (!intBoard[y][x]) intBoard[y][x] = 0;
        }
    }
    return intBoard;
}
var convertIntBoardToString = function(intBoard, board){
    for (let y = 0;y<9;y++){
        for (let x =  0;x < 9;x++){
                board[y][x] = intBoard[y][x].toString();
        }
    }
    
    return board;
}
