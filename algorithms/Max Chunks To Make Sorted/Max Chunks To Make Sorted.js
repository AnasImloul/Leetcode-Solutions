var maxChunksToSorted = function(arr) {
    let count = 0, cumSum = 0;
    arr.forEach((el, index) => {
        cumSum += el-index;
        if (cumSum === 0) count++;
    });
    return count;
};
