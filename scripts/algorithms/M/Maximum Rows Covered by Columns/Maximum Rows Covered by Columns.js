// Runtime: 61 ms (Top 50.0%) | Memory: 45.52 MB (Top 33.3%)

/**
 * @param {number[][]} mat
 * @param {number} cols
 * @return {number}
 */
function getCombinations(n, k) {
    const ans = [];
    const arr = [];
    
    function dfs(i) {
        arr.push(i);
        
        if (arr.length === k) {
            ans.push(Array.from(arr));
            arr.pop();
            return;
        }
        
        for (let j = i + 1; j < n; j++) {
            dfs(j);
        }
        
        arr.pop();
    }
    
    for (let i = 0; i < n; i++) {
        dfs(i);
    }
    
    return ans;
}

var maximumRows = function(mat, cols) {
    const m = mat.length;
    const n = mat[0].length;
    
    let min = 0; // to store no. of rows with all 0's
    let ans = 0;
    
    const map = {}; // to store rows with column numbers having 1's. From ex 1 :- {1: [0, 2], 2: [1, 2]}
    
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (mat[i][j]) {
                if (map[i]) {
                    map[i].push(j); // at row i, jth column is having 1
                } else {
                    map[i] = [j];
                }
            }
        }
        if (!map[i]) { // if all values in row i are 0's
            min++;
        }
    }
	
	// I need more practice on bit masking so I choose backtracking way to get combinations 
    // https://leetcode.com/problems/combinations/discuss/2523710/JavaScript-or-TC-O(n!)-or-SC-O(n)
    const combinations = getCombinations(n, cols); 
    const rows = Object.values(map);
    
	// loop through each combination and see if rows having cell value 1 is chosen or not
    for (const comb of combinations) {
         // assigned min because min contains the count of rows with all 0's (which indicates covered)
		let combAns = min;
        for (const row of rows) {
            // count to check if we reached end of row (all 1's cell of this row are in chosen column combination
			let count = 0; 
            for (let i = 0; i < row.length; i++) {
			// row[i] holds the cell with value 1, and if that doesn't include in the chosen combination, we break the loop. So, this row is not covered.
                if (!comb.includes(row[i])) { 
                    break;
                } else {
                    count++;
                }
            }
            if (count === row.length) {
                combAns++;
            }
        }
		// once we have rows count (combAns) covered by this combination (comb), we take max 
        ans = Math.max(ans, combAns);
    }
    
    return ans;
};