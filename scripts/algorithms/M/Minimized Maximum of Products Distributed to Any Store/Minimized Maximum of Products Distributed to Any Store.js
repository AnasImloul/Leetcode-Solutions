// Runtime: 865 ms (Top 8.70%) | Memory: 71.6 MB (Top 8.70%)
var minimizedMaximum = function(n, quantities) {
    const MAX = Number.MAX_SAFE_INTEGER;
    const m = quantities.length;

    let left = 1;
    let right = quantities.reduce((acc, num) => acc + num, 0);

    let minRes = MAX;

    while (left <= right) {
        const mid = (left + right) >> 1;

        if (canDistribute(mid)) {
            minRes = Math.min(minRes, mid);
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    return minRes;

    function canDistribute(minGiven) {
        const clonedQ = [...quantities];

        let j = 0;
        let i = 0;

        for (; i < n && j < m; ++i) {
            const remQ = clonedQ[j];

            if (remQ > minGiven) {
                clonedQ[j] -= minGiven;
            }
            else {
                ++j;
            }
        }

        return j === m;
    }
};