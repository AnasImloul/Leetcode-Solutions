var gridIllumination = function(n, lamps, queries) {
    const directions = [[0,0], [-1,-1], [-1,0], [-1,1], [0,-1], [0,1], [1,-1], [1,0], [1,1]];
    const lampCoord = new Map();    
    const rowHash = {}, colHash = {}, leftDiag = {}, rightDiag = {};
    
    // First, illuminate the lamps
    for (let [r, c] of lamps) {
        if (lampCoord.has(`${r}-${c}`)) continue;
        lampCoord.set(`${r}-${c}`);
        rowHash[r] = rowHash[r] + 1 || 1;
        colHash[c] = colHash[c] + 1 || 1;
        leftDiag[r + c] = leftDiag[r + c] + 1 || 1;
        rightDiag[c - r] = rightDiag[c - r] + 1 || 1;
    }
    
    // Second, query the lamps
    let output = [];
    for (let [row, col] of queries) query(row, col);
    return output;

    function query(row, col) {
        if (rowHash[row] || colHash[col] || leftDiag[row + col] || rightDiag[col - row]) {
            output.push(1);
			// Check 8 adjacent cells
            for (let [r, c] of directions) {
                let newR = row + r, newC = col + c;
                if (newR < 0 || newC < 0 || newR >= n || newC >= n) continue;
                // If the coordinate is a lamp, un-illuminate the lamp
                if (lampCoord.has(`${newR}-${newC}`)) {
                    rowHash[newR]--, colHash[newC]--, leftDiag[newR + newC]--, rightDiag[newC - newR]--;
                    lampCoord.delete(`${newR}-${newC}`);
                }
            }        
        } else output.push(0);
    }    
};
