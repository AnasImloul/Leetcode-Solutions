// Runtime: 60 ms (Top 97.33%) | Memory: 51.50 MB (Top 90.66%)

var maximumElementAfterDecrementingAndRearranging = function(arr) {
    arr.sort((a, b) => a - b);
    let maxVal = 1;

    for (let i = 1; i < arr.length; i++) {
        if (arr[i] > maxVal) {
            maxVal += 1;
        }
    }

    return maxVal;    
};
