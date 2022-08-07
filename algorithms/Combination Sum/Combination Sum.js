/**
 * @param {number[]} candidates
 * @param {number} target
 * @return {number[][]}
 */
var combinationSum = function(candidates, target) {
    candidates.sort((a, b) => a - b);
    
    const ans = [];
    
    function dfs(i, t, st) {
        if (t === 0) {
            ans.push(Array.from(st));
            return;
        }
        if (i === candidates.length) return;
        
        if (candidates[i] <= t) {
            st.push(candidates[i]);
            dfs(i, t - candidates[i], st);
            st.pop();
        }
        
        dfs(i + 1, t, st);
    }
    
    dfs(0, target, []);
    
    return ans;
};
