var countUnguarded = function(m, n, guards, walls) {
    let board = new Array(m).fill(0).map(_=>new Array(n).fill(0))
    
    // 0 - Empty
    // 1 - Guard
    // 2 - Wall
    // 3 - Guard view
    
    const DIRECTIONS = [
        [-1, 0],
        [0, 1],
        [1, 0],
        [0, -1]
    ]
    
    for(let [guardRow, guardCol] of guards) board[guardRow][guardCol] = 1
    
    for(let [wallRow, wallCol] of walls) board[wallRow][wallCol] = 2
    
    for(let [guardRow, guardCol] of guards){
        //Loop through row with the same col
        //Go down from current row
        let row = guardRow + 1
        while(row < m){
            //Stop if you encounter a wall or guard
            if(board[row][guardCol] == 1 || board[row][guardCol] == 2) break
            board[row][guardCol] = 3
            row++
        }
        //Go up from current row
        row = guardRow - 1
        while(row >= 0){
            if(board[row][guardCol] == 1 || board[row][guardCol] == 2) break
            board[row][guardCol] = 3
            row--
        }
        
        
        //Loop through col with the same row
        //Go right from current col
        let col = guardCol + 1
        while(col < n){
            if(board[guardRow][col] == 1 || board[guardRow][col] == 2) break
            board[guardRow][col] = 3
            col++
        }
        
        //Go left from current col
        col = guardCol - 1
        while(col >= 0){
            if(board[guardRow][col] == 1 || board[guardRow][col] == 2) break
            board[guardRow][col] = 3
            col--
        }
    }
    
	//Count the free cells
    let freeCount = 0
    for(let i = 0; i < m; i++){
        for(let j = 0; j < n; j++){
            if(board[i][j] == 0) freeCount++
        }
    }
    
    return freeCount
};
