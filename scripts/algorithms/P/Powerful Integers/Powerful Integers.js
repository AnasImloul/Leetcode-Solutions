// Runtime: 114 ms (Top 36.00%) | Memory: 41.5 MB (Top 100.00%)
var powerfulIntegers = function(x, y, bound) {
    let ans = new Set()
    for (let xi = 1; xi < bound; xi *= x) {
        for (let yj = 1; xi + yj <= bound; yj *= y) {
            ans.add(xi + yj)
            if (y === 1) break
        }
        if (x === 1) break
    }
    return Array.from(ans)
}