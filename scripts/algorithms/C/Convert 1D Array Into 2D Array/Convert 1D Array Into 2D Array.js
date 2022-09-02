// Runtime: 413 ms (Top 31.46%) | Memory: 81.5 MB (Top 29.47%)
var construct2DArray = function(original, m, n) {
    if (original.length !== (m*n)) return []
    let result = []
    let arr = []
    for (let i = 0; i < original.length; i++){
        arr.push(original[i])
        if (arr.length === n){
            result.push(arr)
            arr = []
        }
    }
    return result
};