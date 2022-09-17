// Runtime: 267 ms (Top 20.55%) | Memory: 67.5 MB (Top 7.22%)
/**
 * @param {number} n
 * @return {number[]}
 */
var grayCode = function(n) {
    return binaryToInt(dfs(n, ['0', '1']))
};

const dfs = (n, arr) => {
    if (n === 1) return arr

    const revArr = [...arr].reverse()

    addOneBefore('0', arr)
    addOneBefore('1', revArr)

    return dfs(n - 1, [...arr, ...revArr])
}

const addOneBefore = (e, arr) => {
    for (let i = 0; i < arr.length; i++) {
        arr[i] = e + arr[i]
    }
}

const binaryToInt = (arr) => {
    for (let i = 0; i < arr.length; i++){
        arr[i] = parseInt(arr[i], 2)
    }
    return arr
}