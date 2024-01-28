// Runtime: 43 ms (Top 98.89%) | Memory: 50.90 MB (Top 5.16%)

var numSpecial = function(mat) {
    function getColumnSum(colIdx) {
        return mat.reduce((sum, row) => sum + row[colIdx], 0);
    }

    let special = 0;
    for (let row of mat) {
        if (row.reduce((acc, val) => acc + val, 0) === 1) {
            const colIdx = row.indexOf(1);
            special += getColumnSum(colIdx) === 1;
        }
    }

    return special;    
};
