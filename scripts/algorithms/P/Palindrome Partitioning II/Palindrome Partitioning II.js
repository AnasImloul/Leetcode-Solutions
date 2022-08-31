// Runtime: 1073 ms (Top 40.58%) | Memory: 43.7 MB (Top 82.61%)
var minCut = function(s) {
    function isPal(l, r) {
        while (l < r) {
            if (s[l] === s[r]) l++, r--;
            else return false;
        } return true;
    }

    let map = new Map();
    function dfs(idx = 0) {
        if (idx === s.length) return 0;
        if (map.has(idx)) return map.get(idx);
        let min = Infinity;
        for (let i = idx; i < s.length; i++) {
            if (isPal(idx, i)) min = Math.min(min, 1 + dfs(i + 1));
        }
        map.set(idx, min);
        return min;
    }

    return dfs() - 1;
};