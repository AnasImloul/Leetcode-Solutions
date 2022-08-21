// Runtime: 390 ms (Top 54.29%) | Memory: 96.8 MB (Top 37.14%)

var findFarmland = function(land) {
    let height = land.length;
    let width = land[0].length;
    let results = [];
    let endRow = 0;
    let endCol = 0;

    let go = (i, j) => {
        if (i < 0 || j < 0 || i >= height || j >= width || land[i][j] === 0) {
            return;
        }

        endRow = Math.max(endRow, i);
        endCol = Math.max(endCol, j);
        land[i][j] = 0; // reset everything to 0

        go(i + 1, j);
        go(i - 1, j);
        go(i, j + 1);
        go(i, j - 1);
    }

    for (let i = 0; i < height; i++) {
        for (let j = 0; j < width; j++) {
            if (land[i][j] === 1) {
                endRow = 0;
                endCol = 0;
                go(i, j);
                results.push([i, j, endRow, endCol]);
            }
        }
    }

    return results;
};