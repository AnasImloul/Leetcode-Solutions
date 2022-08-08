var minHeightShelves = function(books, shelfWidth) {
    let booksArr = []
    
    for(let i = 0; i < books.length; i++) {
        let remainingWidth = shelfWidth - books[i][0]
        let bookHeight = books[i][1]
        
        let maxHeight = bookHeight
        
        let prevSum = booksArr[i - 1] !== undefined ? booksArr[i - 1] : 0
        let minSumHeight = bookHeight + prevSum
        
        for(let x = i - 1; x >= 0 ; x--) {
            
            let prevBookWidth = books[x][0]
            let prevBookHeight = books[x][1]
            if(remainingWidth - prevBookWidth < 0) break
            remainingWidth -= prevBookWidth
            
            prevSum = booksArr[x - 1] !== undefined ? booksArr[x - 1] : 0
            
            maxHeight = Math.max(maxHeight, prevBookHeight)
    
            minSumHeight = Math.min(prevSum  + maxHeight, minSumHeight)
        }
        booksArr[i] = minSumHeight
    }

    return booksArr[books.length - 1]
};
