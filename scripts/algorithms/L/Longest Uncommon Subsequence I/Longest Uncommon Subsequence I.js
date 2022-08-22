// Runtime: 76 ms (Top 70.00%) | Memory: 41.9 MB (Top 62.22%)
var findLUSlength = function(a, b) {
    if (a===b) return -1
    return Math.max(a.length,b.length)

};