// Runtime: 92 ms (Top 97.50%) | Memory: 55.5 MB (Top 40.63%)
/**
 * @param {number[]} nums
 * @param {number} limit
 * @return {number}
 */
var longestSubarray = function(nums, limit) {
    const maxQueue = [];
    const minQueue = [];
    let start = 0;
    let res = 0;
    for(let end = 0; end < nums.length; end ++) {
        const num = nums[end];
        while(maxQueue.length > 0 && maxQueue[maxQueue.length - 1] < num) {
            maxQueue.pop();
        }

        while(minQueue.length > 0 && minQueue[minQueue.length - 1] > num) {
            minQueue.pop();
        }
        maxQueue.push(num);
        minQueue.push(num);
        if(maxQueue[0] - minQueue[0] > limit) {
            if(maxQueue[0] === nums[start]) {
                maxQueue.shift();
            }

            if(minQueue[0] === nums[start]) {
                minQueue.shift();
            }

            start +=1;
        }
        res = Math.max(res, end - start + 1);
    }

    return res;
};