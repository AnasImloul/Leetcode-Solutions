var minCost = function(n, cuts) {
    cuts = cuts.sort((a, b) => a - b);
    let map = new Map();
    // Use cutIdx to track the idx of the cut position in the cuts array
    function dfs(start, end, cutIdx) {
        let key = `${start}-${end}`;
        if (map.has(key)) return map.get(key);
        let min = Infinity
        for (let i = cutIdx; i < cuts.length; i++) {
            let cut = cuts[i];
            if (cut <= start) continue;
            if (cut < end) {
                let len = end - start;
                let left = dfs(start, cut, 0);
                let right = dfs(cut, end, i + 1);
                min = Math.min(min, len + left + right);
            } else break;
        }
        if (min === Infinity) {
            map.set(key, 0);
            return 0;
        }
        else {
            map.set(key, min);
            return min;
        }
    }
    return dfs(0, n, 0);
};
