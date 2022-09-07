// Runtime: 93 ms (Top 42.36%) | Memory: 42 MB (Top 77.09%)
/**
 * @param {number} k
 * @param {number} n
 * @return {number[][]}
 */
var combinationSum3 = function(k, n) {
    const ans = [];
    const st = [];

    function dfs(start, t) {
        if (t === 0 && st.length === k) {
            ans.push(Array.from(st));
            return;
        }
        for (let i = start; i <= 9 && st.length < k; i++) {
            if (i > t) break;
            st.push(i);
            dfs(i + 1, t - i);
            st.pop();
        }
    }

    dfs(1, n);

    return ans;
};