// Runtime: 1929 ms (Top 21.74%) | Memory: 140.6 MB (Top 8.70%)
var minAbsDifference = function(nums, goal) {
    let mid = Math.floor(nums.length / 2);
    let part1 = nums.slice(0, mid), part2 = nums.slice(mid);

    function findSubsetSums(arr, set, idx = 0, sum = 0) {
        if (idx === arr.length) return set.add(sum);
        findSubsetSums(arr, set, idx + 1, sum);
        findSubsetSums(arr, set, idx + 1, sum + arr[idx]);
    }

    let sum1 = new Set(), sum2 = new Set();
    findSubsetSums(part1, sum1);
    findSubsetSums(part2, sum2);

    sum1 = [...sum1.values()];
    sum2 = [...sum2.values()];
    sum2.sort((a, b) => a - b);

    let min = Infinity;
    for (let num1 of sum1) {
        let l = 0, r = sum2.length - 1;
        while (l <= r) {
            let mid = l + Math.floor((r - l) / 2);
            let num2 = sum2[mid];
            min = Math.min(min, Math.abs(num1 + num2 - goal));
            if (num1 + num2 < goal) l = mid + 1;
            else r = mid - 1;
        }
    }
    return min;
};