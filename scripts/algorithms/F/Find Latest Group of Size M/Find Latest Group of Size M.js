// Runtime: 198 ms (Top 72.22%) | Memory: 54.2 MB (Top 88.89%)
var findLatestStep = function(arr, m) {
    if (m === arr.length) return arr.length
    let bits = new Array(arr.length+1).fill(true), pos, flag, i, j
    for (i = arr.length - 1, bits[0] = false; i >= 0; i--) {
        pos = arr[i], bits[pos] = false
        for (j = 1, flag = true; flag && j <= m; j++) flag = bits[pos-j]
        if (flag && !bits[pos-m-1]) return i
        for (j = 1, flag = true; flag && j <= m; j++) flag = bits[pos+j]
        if (flag && !bits[pos+m+1]) return i
    }
    return -1
};