// Runtime: 6038 ms (Top 9.09%) | Memory: 48.9 MB (Top 27.27%)
const maxNumber = (a, b, k) => {
    let m = a.length, n = b.length;
    let res = [];
    for (let i = Math.max(0, k - n); i <= Math.min(k, m); i++) {
        let maxA = maxArray(a, i), maxB = maxArray(b, k - i);
        let merge = mergeArray(maxA, maxB);
        if (merge > res) res = merge;
    }
    return res;
};

const maxArray = (a, k) => {
    let drop = a.length - k, res = [];
    for (const x of a) {
        while (drop > 0 && res.length && res[res.length - 1] < x) {
            res.pop();
            drop--;
        }
        res.push(x);
    }
    if (res.length >= k) {
        res = res.slice(0, k);
    } else {
        res = res.concat(Array(k - res.length).fill(0));
    }
    return res;
};

const mergeArray = (a, b) => {
    let res = [];
    while (a.length + b.length) res.push(a > b ? a.shift() : b.shift())
    return res;
};