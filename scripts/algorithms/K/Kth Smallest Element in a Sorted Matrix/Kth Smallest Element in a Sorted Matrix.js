// Runtime: 148 ms (Top 40.32%) | Memory: 48.3 MB (Top 41.17%)
var kthSmallest = function(matrix, k) {
    let arr = matrix.flat()
    arr.sort((a,b)=>a-b)
    return arr[k-1]
};