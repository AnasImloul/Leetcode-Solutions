// Runtime: 75 ms (Top 81.08%) | Memory: 44.3 MB (Top 51.35%)

var numTilings = function(n) {
    let mod = 10 ** 9 + 7;
    let len = 4;
    let ways = new Array(len).fill(0);

    // base cases
    ways[0] = 1;
    ways[1] = 1;
    ways[2] = 2;

    // already calculated above
    if (n < len - 1) {
        return ways[n];
    }

    // use % len to circulate values inside our array
    for (var i = len - 1; i <= n;i++) {
        ways[i % len] = (
            ways[(len + i - 1) % len] * 2
            +
            ways[(len + i - 3) % len]
        ) % mod;
    }

    return ways[(i - 1) % len];
};