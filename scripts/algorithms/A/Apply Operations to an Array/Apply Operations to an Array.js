// Runtime: 57 ms (Top 73.96%) | Memory: 51.20 MB (Top 8.04%)

var applyOperations = function(nums) {
// perform the operation on each array element
    for(let i = 0; i < nums.length - 1; i++){
        if(nums[i] === nums[i + 1]){
            nums[i] *= 2;
            nums[i + 1] = 0;
        }
    }
// Move zeroes to end
    let index = 0;
    nums.forEach(num => {
        if(num !== 0)
            nums[index++] = num;
    });
    while(index < nums.length){
        nums[index++] = 0;
    }
    return nums;
};
