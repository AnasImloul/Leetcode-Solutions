// Runtime: 92 ms (Top 43.48%) | Memory: 41.8 MB (Top 59.42%)
var maxChunksToSorted = function(arr) {
    let count = 0, cumSum = 0;
    arr.forEach((el, index) => {
        cumSum += el-index;
        if (cumSum === 0) count++;
    });
    return count;
};