// Runtime: 82 ms (Top 78.5%) | Memory: 46.23 MB (Top 57.1%)

var maximumCostSubstring = function(s, chars, vals) {
    let max = 0, ans = 0, values = Array.from({ length: 26 }, (_, i) => i + 1);
    for (let i = 0; i < chars.length; i++)
        values[chars.charCodeAt(i) - 97] = vals[i];

    for (const char of s) {
        max = Math.max(0, max + values[char.charCodeAt() - 97]);
        ans = Math.max(ans, max)
    }

    return ans;
};