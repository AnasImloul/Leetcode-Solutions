// Runtime: 124 ms (Top 40.7%) | Memory: 50.74 MB (Top 23.6%)

var minDifference = function(nums) {
    let len = nums.length;
    if (len < 5) return 0;

    nums.sort((a,b) => a-b)
    
    return Math.min(
        
    ( nums[len-1] - nums[3] ),  // 3 elements removed from start 0 from end
    ( nums[len-4] - nums[0] ),  // 3 elements removed from end 0 from start
    ( nums[len-2] - nums[2] ),  // 2 elements removed from start 1 from end
    ( nums[len-3] - nums[1] ),  // 2 elements removed from end 1 from start
   

)
    
    
    
      
};