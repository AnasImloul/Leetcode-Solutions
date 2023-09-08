// Runtime: 95 ms (Top 77.7%) | Memory: 59.21 MB (Top 55.5%)

var maxNonOverlapping = function(nums, target) {
    const prefixSum = new Set([0]);
    let current = result = 0;

    for (let index = 0; index < nums.length; index++) {
        current += nums[index];

        if (prefixSum.has(current - target)) {
            current = 0;
            result += 1;
            prefixSum.clear();
            prefixSum.add(0);
        } 
        else prefixSum.add(current);
    }
    return result;
};