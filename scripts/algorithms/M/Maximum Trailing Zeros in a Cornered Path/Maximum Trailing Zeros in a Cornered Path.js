// Runtime: 1099 ms (Top 20.00%) | Memory: 131.8 MB (Top 60.00%)
var maxTrailingZeros = function(grid) {
    const m = grid.length;
    const n = grid[0].length;

    const postfixCols = [];

    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            const num = grid[i][j];

            if (postfixCols[j] == null) postfixCols[j] = { 2: 0, 5: 0 };

            postfixCols[j]["2"] += getCount(num, 2);
            postfixCols[j]["5"] += getCount(num, 5);
        }
    }

    const prefixCols = [];

    for (let j = 0; j < n; ++j) {
        prefixCols[j] = { 0: 0, 2: 0, 5: 0 };
    }

    let maxZeros = 0;

    for (let i = 0; i < m; ++i) {
        const postfixRow = { 0: 0, 2: 0, 5: 0 };

        for (let j = n - 1; j >= 0; --j) {
            const num = grid[i][j];

            postfixRow["2"] += getCount(num, 2);
            postfixRow["5"] += getCount(num, 5);
        }

        let prefixRow = { 0: 0, 2: 0, 5: 0 };

        for (let j = 0; j < n; ++j) {
            const num = grid[i][j];

            const twoCount = getCount(num, 2);
            const fiveCount = getCount(num, 5);

            postfixRow["2"] -= twoCount;
            postfixCols[j]["2"] -= twoCount;

            postfixRow["5"] -= fiveCount;
            postfixCols[j]["5"] -= fiveCount;

            // down-right => prefixCol + postfixRow
            const downRight = calculateTrailingZeros(prefixCols[j], postfixRow, num);
            // down-left => prefixCol + prefixRow
            const downLeft = calculateTrailingZeros(prefixCols[j], prefixRow, num);
            // up-right => postfixCols + postfixRow
            const upRight = calculateTrailingZeros(postfixCols[j], postfixRow, num);
            // up-left => postfixCols + prefixRow
            const upLeft = calculateTrailingZeros(postfixCols[j], prefixRow, num);

            maxZeros = Math.max(maxZeros, downRight, downLeft, upRight, upLeft);

            prefixRow["2"] += twoCount;
            prefixCols[j]["2"] += twoCount;

            prefixRow["5"] += fiveCount;
            prefixCols[j]["5"] += fiveCount;
        }
    }

    return maxZeros;

    function calculateTrailingZeros(col, row, currNum) {
        let twosCount = 0;
        let fivesCount = 0;
        let zerosCount = 0;

        twosCount = row["2"] + col["2"];
        fivesCount = row["5"] + col["5"];

        twosCount += getCount(currNum, 2);
        fivesCount += getCount(currNum, 5);
        return Math.min(twosCount, fivesCount);
    }

    function getCount(num, divisor) {
        let count = 0;

        while (num % divisor === 0) {
            ++count;
            num /= divisor;
        }

        return count;
    }
};