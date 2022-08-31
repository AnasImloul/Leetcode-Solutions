// Runtime: 2425 ms (Top 13.72%) | Memory: 77.5 MB (Top 19.61%)
var numberOfWays = function(s) {
    const len = s.length;
    const prefix = new Array(len).fill(0).map(() => new Array(2).fill(0));
    for(let i = 0; i < len; i++) {
        const idx = s[i] == '1' ? 1 : 0;
        if(i == 0) prefix[i][idx]++;
        else {
            prefix[i] = Array.from(prefix[i-1]);
            prefix[i][idx]++;
        }
    }
    let ans = 0;
    for(let i = 1; i < len - 1; i++) {
        const c = s[i] == '1' ? 0 : 1;
        ans += (prefix.at(-1)[c] - prefix[i][c]) * prefix[i-1][c];
    }
    return ans;
};