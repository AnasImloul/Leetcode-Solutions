// Runtime: 57 ms (Top 37.81%) | Memory: 42.20 MB (Top 49.25%)

/**
 * @param {number[]} nums
 * @return {number}
 */
var specialArray = function(nums) {
    // step 1: sort
    nums = nums.sort((a,b) => a-b);
    // step 2: search
    for(let i=nums.length; i>=0; i--) {
        // found:
        if(bs(nums, i)) return i;
    }
    // not found:
    return -1;
};

function bs(array, target) {
    let left = 0;
    let right = array.length - 1;

    while(left <= right){
        const mid = Math.floor((left+right)/2);
        if(array[mid] < target) left = mid + 1;
        else right = mid - 1;
    }

    const greaterThanTarget = array.length - left;

    return greaterThanTarget === target;
}
