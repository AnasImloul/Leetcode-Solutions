// Runtime: 3324 ms (Top 13.04%) | Memory: 55 MB (Top 57.61%)
var minOperations = function(nums, numsDivide) {
    nums.sort((a,b) => a - b)
    let set = new Set()

    for (let i=0; i < nums.length; i++) {
        let item = nums[i]
        if (!set.has(item)) {
            let quantity = 0;

            for (let j=0; j < numsDivide.length; j++) {
                if (numsDivide[j] % item !== 0) {
                    set.add(item);
                    quantity = nums.lastIndexOf(item) - i + 1;
                    break;
                }
            }

        if (quantity === 0) return i;
        }
    }

    return -1;
};