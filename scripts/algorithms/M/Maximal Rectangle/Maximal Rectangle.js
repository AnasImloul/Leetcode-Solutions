// Runtime: 186 ms (Top 17.87%) | Memory: 45.1 MB (Top 72.77%)
var maximalRectangle = function(matrix) {
    const m = matrix.length;
    const n = matrix[m - 1].length;

    const prefixSum = new Array(m).fill().map(() => new Array(n).fill(0));
    for(let i = 0; i < m; i += 1) {
        for(let j = 0; j < n; j += 1) {
            prefixSum[i][j] = parseInt(matrix[i][j]);
            if(i > 0 && prefixSum[i][j] > 0) {
                prefixSum[i][j] += prefixSum[i - 1][j];
            }
        }
    }

    const getArea = (currentRow) => {
        let max = 0;
        for(let i = 0; i < n; i += 1) {
            const height = currentRow[i];

            let leftBoundary = i;
            while(leftBoundary >= 0 && currentRow[leftBoundary] >= currentRow[i]) {
                leftBoundary -= 1;
            }

            let rightBoundary = i;
            while(rightBoundary < n && currentRow[rightBoundary] >= currentRow[i]) {
                rightBoundary += 1;
            }

            const width = rightBoundary - leftBoundary - 1;
            max = Math.max(max, height * width);
        }

        return max;
    }

    let max = 0;
    for(let i = 0; i < m; i += 1) {
        max = Math.max(max, getArea(prefixSum[i]));
    }

    return max;
};