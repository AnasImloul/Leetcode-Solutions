var kthSmallest = function(matrix, k) {
    let arr = matrix.flat()
    arr.sort((a,b)=>a-b)
    return arr[k-1]
};
