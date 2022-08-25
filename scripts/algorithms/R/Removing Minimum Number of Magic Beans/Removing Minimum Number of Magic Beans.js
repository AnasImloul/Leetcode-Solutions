// Runtime: 419 ms (Top 42.86%) | Memory: 59 MB (Top 60.32%)
/**
 * @param {number[]} beans
 * @return {number}
 */
var minimumRemoval = function(beans) {
    const N = beans.length;
    const sum = beans.reduce((acc, c) => c + acc, 0);

    beans.sort((a,b) => a - b);

    let ans = Infinity;
    for(let i = 0 ; i < beans.length; i++) {
        ans = Math.min(ans, sum - (N - i) * beans[i])
    }

    return ans;
};
// TC: O(NlogN) for sorting
// SC: O(1)