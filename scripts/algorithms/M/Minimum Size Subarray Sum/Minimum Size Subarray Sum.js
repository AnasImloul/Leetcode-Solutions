// Runtime: 134 ms (Top 14.15%) | Memory: 46.1 MB (Top 74.97%)
/**
 * @param {number} target
 * @param {number[]} nums
 * @return {number}
 */
var minSubArrayLen = function(target, nums) {
    let indexStartPosition = 0;
    let sum = 0;
    let tempcounter = 0;
    let counter = Infinity;

    for(var indexI=0; indexI<nums.length; indexI++){
           sum = sum + nums[indexI];
        tempcounter++;

        while(sum >= target) {
           sum = sum - nums[indexStartPosition];
           indexStartPosition = indexStartPosition + 1;
           counter = Math.min(counter, tempcounter);
           tempcounter--;
        }

    }

    return counter === Infinity ? 0 : counter;
};