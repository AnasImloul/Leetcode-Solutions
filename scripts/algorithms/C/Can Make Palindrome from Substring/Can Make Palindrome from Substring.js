// Runtime: 315 ms (Top 46.15%) | Memory: 86.7 MB (Top 38.46%)
const getBitCount = (n) => {
    let cnt = 0;
    while(n > 0) {
        cnt += n & 1;
        n >>= 1;
    }
    return cnt;
}

var canMakePaliQueries = function(s, queries) {
    const masks = [0], base = 'a'.charCodeAt(0);
    let mask = 0;
    for(let c of s) {
        mask ^= (1 << (c.charCodeAt(0) - base));
        masks.push(mask);
    }
    return queries.map(([l, r, k]) => {
        const cnt = getBitCount(masks[l] ^ masks[r+1]);
        return cnt - 1 <= 2 * k
    });
};