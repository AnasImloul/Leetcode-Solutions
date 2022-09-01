// Runtime: 114 ms (Top 31.62%) | Memory: 46.2 MB (Top 10.29%)
/**
 * @param {number[][]} matrix
 * @return {number[]}
 */
var luckyNumbers = function(matrix) {
    let rowLucky = new Set();
    let colLucky = new Set();
    let cols = [...Array(matrix[0].length)].map(e => []);

    for (let i = 0; i < matrix.length; i++) {
        let row = matrix[i];
        rowLucky.add(Math.min(...row));

        // build columns
        for (let j = 0; j < row.length; j++) {
            cols[j].push(row[j]);
        }
    }

    // Compare sets
    for (const col of cols)
        colLucky.add(Math.max(...col));
    return [...rowLucky].filter(x => colLucky.has(x));
};