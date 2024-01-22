// Runtime: 317 ms (Top 73.49%) | Memory: 75.60 MB (Top 73.49%)

var NumMatrix = function(matrix) {

    let R = matrix.length
    let C = matrix[0].length

    this.sumMatrix = Array.from({length: R + 1}, () => new Array(C + 1).fill(0))

    for (let r = 0; r < R; r++) {

        let prefix = 0

        for (let c = 0; c < C; c++) {

            prefix += matrix[r][c]

            let above = this.sumMatrix[r][c + 1]

            this.sumMatrix[r + 1][c + 1] = prefix + above
        }

    }
    
};

NumMatrix.prototype.sumRegion = function(row1, col1, row2, col2) {

    row1 = row1 + 1
    col1 = col1 + 1
    row2 = row2 + 1
    col2 = col2 + 1

    let bottomRight = this.sumMatrix[row2][col2]
    let above = this.sumMatrix[row1 - 1][col2]
    let left = this.sumMatrix[row2][col1 - 1]
    let topLeft = this.sumMatrix[row1 - 1][col1 - 1]

    return bottomRight - above - left + topLeft
    
};

/** 
 * Your NumMatrix object will be instantiated and called as such:
 * var obj = new NumMatrix(matrix)
 * var param_1 = obj.sumRegion(row1,col1,row2,col2)
 */
