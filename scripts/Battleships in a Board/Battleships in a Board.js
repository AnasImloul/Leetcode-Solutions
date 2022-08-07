var countBattleships = function(board) {
    
    let count = 0;
    
    for(let rowIndex = 0; rowIndex < board.length; rowIndex++){
        for(let columnIndex = 0; columnIndex < board[rowIndex].length; columnIndex++){
            const isTopEmpty = rowIndex === 0 || board[rowIndex - 1][columnIndex] !== "X";
            const isLeftEmpty = columnIndex === 0 || board[rowIndex][columnIndex - 1] !== "X";
            const isBattleShip = board[rowIndex][columnIndex] === "X" && isTopEmpty && isLeftEmpty;
            if(isBattleShip){
                count++;
            }
        }
    }
    
    return count;
    
};
