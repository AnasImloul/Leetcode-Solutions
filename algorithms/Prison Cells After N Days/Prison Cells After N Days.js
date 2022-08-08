/**
 * @param {number[]} cells
 * @param {number} n
 * @return {number[]}
 */

var prisonAfterNDays = function(cells, n) {
    const set = new Set()
    let cycleDuration = 0
    
    while(n--) {
        const nextCells = getNextCells(cells)

        // 1. Get cycle length
        if(!set.has(String(nextCells))){
            set.add(String(nextCells))
            cycleDuration++
            cells = nextCells
            
        } else {
            // 2. Use cycle length to iterate once more to get to correct order
            let remainderToMove = n%cycleDuration
            while(remainderToMove >= 0) {
                remainderToMove--
                cells = getNextCells(cells)
            }
            break
        }        
        
    }
    
    return cells
};

function getNextCells(cells) {
    let temp = [...cells]
    for(let i = 0; i < 8; i++) {
        if(i>0 && i < 7 && cells[i-1] === cells[i+1]) {
            temp[i] = 1
        } else {
            temp[i] = 0
        }
    }

    return temp
}

// 0
// 1
// 2
// n

// 1 000 000 % n 
