// Runtime: 74 ms (Top 97.37%) | Memory: 44.7 MB (Top 10.53%)
var constructArray = function(n, k) {
    const result = [];
    let left = 1;
    let right = n;

    for (let index = 0; index < n; index++) {
        if (k === 1) {
            result.push(left++);
            continue;
        }
        const num = k & 1 ? left++ : right--;
        result.push(num);
        k -= 1;
    }

    return result;
};