/**
 * @param {number[]} candidates
 * @param {number} target
 * @return {number[][]}
 */
var combinationSum2 = function(candidates, target) {
    candidates.sort((a, b) => a - b);
    
    const ans = [];
    
    function dfs(idx, t, st) {
        if (t === 0) {
            ans.push(Array.from(st));
            return;
        }
        for (let i = idx; i < candidates.length; i++) {
            if (i > idx && candidates[i - 1] === candidates[i]) continue;
            if (candidates[i] > t) break;
            st.push(candidates[i]);
            dfs(i + 1, t - candidates[i], st);
            st.pop();
        }
    }
    
    dfs(0, target, []);
    
    return ans;
};
