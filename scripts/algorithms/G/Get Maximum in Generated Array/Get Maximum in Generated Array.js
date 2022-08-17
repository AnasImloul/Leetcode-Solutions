var getMaximumGenerated = function(n) {
    if (n === 0) return 0;
    if (n === 1) return 1;
    let arr = [0, 1];
    let max = 0;
    for (let i = 0; i < n; i++) {
        if (2 <= 2 * i && 2 * i <= n) {
            arr[2 * i] = arr[i]
            if (arr[i] > max) max = arr[i];
        }
        if (2 <= 2 * i && 2 * i + 1 <= n) {
            arr[2 * i + 1] = arr[i] + arr[i + 1]
            if (arr[i] + arr[i + 1] > max) max = arr[i] + arr[i + 1];
        };
    }
    return max;
};
