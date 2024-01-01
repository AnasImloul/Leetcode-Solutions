// Runtime: 49 ms (Top 100.0%) | Memory: 43.10 MB (Top 40.0%)

/**
 * @param {string[]} strs
 * @return {number}
 */
var minDeletionSize = function(strs) {
    if (strs.length === 0) return 0
    let dp = new Array(strs[0].length).fill(1)
    for (let i = 1; i < strs[0].length; i++) {
        for (let j = 0; j < i; j++) {
            let flag = true
            for (let k = 0; k < strs.length; k++) {
                if (strs[k][j] > strs[k][i]) {
                    flag = false
                    break
                }
            }
            if (flag) {
                dp[i] = Math.max(dp[i], dp[j] + 1)
            }
        }
    }
    return strs[0].length - Math.max(...dp)
};
