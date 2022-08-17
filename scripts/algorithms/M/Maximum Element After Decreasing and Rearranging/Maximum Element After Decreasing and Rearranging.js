var maximumElementAfterDecrementingAndRearranging = function(arr) {
    if (!arr.length) return 0
    arr.sort((a, b) => a - b)
    arr[0] = 1
    for (let i = 1; i < arr.length; i++) {
        if (Math.abs(arr[i] - arr[i - 1]) > 1) arr[i] = arr[i - 1] + 1
    }
    return arr.at(-1)
};
