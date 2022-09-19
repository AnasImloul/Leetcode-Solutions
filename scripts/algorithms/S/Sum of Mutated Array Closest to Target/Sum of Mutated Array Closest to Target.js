// Runtime: 114 ms (Top 45.10%) | Memory: 43.1 MB (Top 78.43%)
var findBestValue = function(arr, target) {
    const n = arr.length;
    const max = Math.max(...arr);

    let left = 0;
    let right = max;

    let prevSum = Number.MIN_SAFE_INTEGER;
    let prevVal = -1;

    while (left <= right) {
        const mid = left + Math.floor((right - left) / 2);

        const currSum = changeSum(mid);

        if (currSum === target) return mid;

        const currDiff = Math.abs(target - currSum);
        const prevDiff = Math.abs(target - prevSum);

        if (currDiff < prevDiff || (currDiff === prevDiff && mid < prevVal)) {
            prevSum = currSum;
            prevVal = mid;
        }

        if (currSum < target) left = mid + 1;
        else right = mid - 1;
    }

    return prevVal;

    function changeSum(value) {
        let sum = 0;

        for (let i = 0; i < n; i++) {
            const num = arr[i];

            if (num > value) sum += value;
            else sum += num;
        }

        return sum;
    }
};