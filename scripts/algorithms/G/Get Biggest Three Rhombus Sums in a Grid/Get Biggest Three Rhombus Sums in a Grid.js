// Runtime: 837 ms (Top 5.88%) | Memory: 54.6 MB (Top 67.65%)
var getBiggestThree = function(grid) {
    const m = grid.length;
    const n = grid[0].length;

    const set = new Set();

    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            let sum = grid[i][j];

            set.add(sum)

            let len = 1;
            let row = i;
            let col = j;

            while (withinBound(row + 1, col - 1)) {
                ++len;
                ++row;
                --col;

                traverse(i, j, row, col, sum, len, 0, "botRight");
                sum += grid[row][col];
            }
        }
    }

    let max1;
    let max2;
    let max3;

    for (const num of set) {
        if (max1 == null || num > max1) {
            max3 = max2;
            max2 = max1;
            max1 = num;
        }
        else if (max2 == null || num > max2) {
            max3 = max2;
            max2 = num;
        }
        else if (max3 == null || num > max3) {
            max3 = num;
        }
    }

    const res = [];

    if (max1) res[0] = max1;
    if (max2) res[1] = max2;
    if (max3) res[2] = max3;

    return res;

    function traverse(destRow, destCol, currRow, currCol, totSum, lenSize, currLen, currDir) {
        if (currRow === destRow && currCol === destCol) {
            set.add(totSum);
            return;
        }

        totSum += grid[currRow][currCol];
        ++currLen;

        if (currDir === "botRight") {
            if (currLen < lenSize) {
                if (!withinBound(currRow + 1, currCol + 1)) return;

                traverse(destRow, destCol, currRow + 1, currCol + 1, totSum, lenSize, currLen, currDir);
            }
            else if (currLen === lenSize) {
                if (!withinBound(currRow - 1, currCol + 1)) return;

                traverse(destRow, destCol, currRow - 1, currCol + 1, totSum, lenSize, 1, "topRight");
            }
        }
        else if (currDir === "topRight") {
            if (currLen < lenSize) {
                if (!withinBound(currRow - 1, currCol + 1)) return;

                traverse(destRow, destCol, currRow - 1, currCol + 1, totSum, lenSize, currLen, "topRight");
            }
            else if (currLen === lenSize) {
                if (!withinBound(currRow - 1, currCol - 1)) return;

                traverse(destRow, destCol, currRow - 1, currCol - 1, totSum, lenSize, 1, "topLeft");
            }
        }
        else if (currDir === "topLeft") {
            if (!withinBound(currRow - 1, currCol - 1)) return;

            traverse(destRow, destCol, currRow - 1, currCol - 1, totSum, lenSize, currLen, "topLeft");
        }
    }

    function withinBound(row, col) {
        return row >= 0 && col >= 0 && row < m && col < n;
    }
};