// Runtime: 57 ms (Top 60.0%) | Memory: 42.00 MB (Top 98.0%)

var trimMean = function(arr) {
    arr.sort((a,b)=>a-b);
    let  sum = 0;
    for (let i = arr.length / 20; i < arr.length - arr.length / 20; i++) {
        sum += arr[i];
    }
    return sum / (arr.length - arr.length / 10);
};
