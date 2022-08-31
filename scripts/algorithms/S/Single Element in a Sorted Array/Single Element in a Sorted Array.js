// Runtime: 63 ms (Top 96.12%) | Memory: 45.3 MB (Top 33.50%)
var singleNonDuplicate = function(nums) {
    var start = 0;
    var end = nums.length - 1
    // to check one element
     if (nums.length == 1) return nums[start]
     while(start <= end) {
        if(nums[start] != nums[start + 1]) {
            return nums[start] }

          if(nums[end] != nums[end - 1]) {
            return nums[end]
        }
        // increment two point
        start = start + 2;
        end = end - 2;

    }
};