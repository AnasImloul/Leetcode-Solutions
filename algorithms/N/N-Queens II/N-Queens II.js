/**
 * @param {number} n
 * @return {number}
 */
var totalNQueens = function(n) {
	// Keep track of columns with queens
    const cols = new Set();
	// Keep track of positive slope diagonal by storing row number + column number
    const posDiag = new Set();
	// Keep track of negative slope diagonal by storing row number - column number
    const negDiag = new Set();
	// Count of valid boards
    let count = 0;
    
    const backtrack = function(r) {
		// Base case to end recursion, we have traversed board and found valid position in each row
        if(r === n) {
            count += 1;
            return;
        }
		// Loop through each column to see if you can place a queen
        for(let c = 0; c < n; c++) {
			// invalid position check, if position in set we cannot place queen here
            if(cols.has(c) || posDiag.has(r+c) || negDiag.has(r-c)) continue;
            
			// add new queen to sets
            cols.add(c);
            posDiag.add(r+c);
            negDiag.add(r-c);
            
			// backtrack
            backtrack(r+1);
            
			// remove current position from sets because backtracking for this position is complete
            cols.delete(c);
            posDiag.delete(r+c);
            negDiag.delete(r-c);
        }
    }
    
    backtrack(0);
    return count;
};
