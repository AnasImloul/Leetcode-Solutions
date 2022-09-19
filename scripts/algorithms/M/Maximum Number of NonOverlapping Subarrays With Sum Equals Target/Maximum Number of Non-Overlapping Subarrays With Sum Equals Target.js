// Runtime: 196 ms (Top 36.00%) | Memory: 56.5 MB (Top 60.00%)
var maxNonOverlapping = function(nums, target) {
    const seen = new Set();
    let total = 0, result = 0;

    for(let n of nums) {
        total += n;

        if(total === target || seen.has(total - target)) {
            total = 0;
            result++;
            seen.clear()
        } else seen.add(total)
    }
    return result;
};