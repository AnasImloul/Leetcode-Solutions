// Runtime: 82 ms (Top 57.1%) | Memory: 55.85 MB (Top 7.1%)

var maxAbsValExpr = function(arr1, arr2) {
    const l1 = [], l2 = [], l3 = [], l4 = [], res = [];
    
    for (let i = 0; i < arr1.length; i++) {
        l1.push(arr1[i] + arr2[i] + i)
        l2.push(arr1[i] - arr2[i] + i)
        l3.push(-arr1[i] + arr2[i] + i)
        l4.push(-arr1[i] - arr2[i] + i)
    }
    
    res.push(Math.max(...l1) - Math.min(...l1))
    res.push(Math.max(...l2) - Math.min(...l2))
    res.push(Math.max(...l3) - Math.min(...l3))
    res.push(Math.max(...l4) - Math.min(...l4))
    
    return Math.max(...res);
};