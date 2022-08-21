// Runtime: 104 ms (Top 32.99%) | Memory: 42.2 MB (Top 52.58%)

var countHillValley = function(nums) {
    let previous;
    let count = 0;
    for (let i=0; i<nums.length; i++) {
        if (previous === undefined) {
            previous = i;
            continue;
        }
        if (nums[i-1] === nums[i]) {
            continue;
        }
        let nextCheck = i + 1;
        while(nums[nextCheck] === nums[i]) {
              nextCheck++;
        }
        if(nums[i] > nums[previous] && nums[i] > nums[nextCheck]) {
            count++;
        }
        if(nums[i] < nums[previous] && nums[i] < nums[nextCheck]) {
            count++;
        }
        previous = i;
        i = nextCheck - 1;
    }
    return count;
};