var trimMean = function(arr) {
    arr.sort((a,b) => a - b);
    let toDelete = arr.length / 20;
    let sum = 0;
    for (let i = toDelete; i < arr.length - toDelete; i++) {
        sum += arr[i];
    }
    return sum / (arr.length - (2 * toDelete));
};
