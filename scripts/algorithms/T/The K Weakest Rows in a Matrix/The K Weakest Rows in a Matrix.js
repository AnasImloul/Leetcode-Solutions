// Runtime: 84 ms (Top 72.55%) | Memory: 43.7 MB (Top 93.76%)
/**
 * @param {number[][]} mat
 * @param {number} k
 * @return {number[]}

 * S: O(N)
 * T: O(N*logN)
 */
var kWeakestRows = function(mat, k) {
    return mat.reduce((acc, row, index) => {
        let left = 0;
        let right = row.length - 1;

        while(left <= right) {
            let mid = Math.floor( (left + right) / 2);

            if(row[mid]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        acc.push({ index, value: left });

        return acc;
    }, []).sort((a, b) => a.value - b.value).splice(0, k).map(item => item.index);
};