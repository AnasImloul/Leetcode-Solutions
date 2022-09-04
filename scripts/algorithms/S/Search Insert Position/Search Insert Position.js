// Runtime: 71 ms (Top 81.32%) | Memory: 42.7 MB (Top 14.71%)
var searchInsert = function(nums, target) {
    let start=0;
    let end= nums.length-1;

    while(start <= end) {
        const mid = Math.trunc((start+end)/2);
        if(nums[mid] === target) {
            return mid;
        }
        if(nums[mid] < target) {
            start = mid+1;
        } else {
            end = mid-1
        }
        if(nums[end]< target){
          return end+1;
        }

        if(nums[start] > target){
          return start;
        }
    }
};