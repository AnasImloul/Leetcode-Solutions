// Helper counts how many ones are in the matrix to start with. O(mn)
var countOnes = function(mat) {
    let count = 0;
    for (let r = 0; r < mat.length; r++) {
        count += mat[r].reduce((a, b) => a + b);
    }
    return count;
}

// Helper flips a cell and its neighbors. Returns updated number of ones left in matrix. O(1)
var flip = function(mat, r, c, numOnes) {
    const dirs = [[0, 1], [0, -1], [1, 0], [-1, 0], [0, 0]];
    dirs.forEach(el => {
        let newR = r + el[0], newC = c + el[1];
        if (newR >= 0 && newR < mat.length && newC >= 0 && newC < mat[0].length) {
            if (mat[newR][newC] === 0) {
                mat[newR][newC] = 1;
                numOnes++;
            } else {
                mat[newR][newC] = 0;
                numOnes--;
            }
        }
    })
    return numOnes;
}

// Main function tries every possible combination of cells being flipped using backtracking. O (2^(mn))
var minFlips = function(mat) {
    const rows = mat.length, cols = mat[0].length;
    let minFlips = Infinity, numOnes = countOnes(mat);
    
    var backtrackFlip = function(cell, flips) {
        if (numOnes === 0) minFlips = Math.min(minFlips, flips);
        for (let newCell = cell; newCell < rows * cols; newCell++) {
			// Function uses a cell number instead of row / col to keep track of column flips
			// For example, a 2 x 2 grid has cells "0", "1", "2", "3" and the line below calculates row / col based on that number
            const r = Math.floor(newCell / cols), c = newCell % cols;
            numOnes = flip(mat, r, c, numOnes);
            backtrackFlip(newCell + 1, flips + 1);
            numOnes = flip(mat, r, c, numOnes);
        }
    }
    
    backtrackFlip(0, 0);
    return minFlips === Infinity ? -1 : minFlips;
    
};
