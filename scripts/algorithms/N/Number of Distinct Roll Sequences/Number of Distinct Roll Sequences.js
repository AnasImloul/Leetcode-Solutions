// Runtime: 760 ms (Top 53.85%) | Memory: 83.1 MB (Top 23.08%)
var distinctSequences = function(n) {
    // 3D DP [n + 1][7][7] => rollIdx, prev, prevPrev
    const dp = Array.from({ length: n + 1}, () => {
        return new Array(7).fill(0).map(() => new Array(7).fill(0));
    });

    const gcd = (a, b) => {
        if(a < b) [b, a] = [a, b];
        while(b) {
            let temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    const ds = (n, p = 0, pp = 0) => {
        if(n == 0) return 1;
        if(dp[n][p][pp] == 0) {
            for(let i = 1; i <= 6; i++) {
                if((i != p && i != pp) && (p == 0 || gcd(p, i) == 1)) {
                    dp[n][p][pp] = (dp[n][p][pp] + ds(n - 1, i, p)) % 1000000007;
                }
            }
        }
        return dp[n][p][pp];
    }
    return ds(n);
};