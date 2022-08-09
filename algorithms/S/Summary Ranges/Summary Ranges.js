
var summaryRanges = function(nums) {
    let result = [];
    let startIdx = 0; 
    
    for(let i = 0; i < nums.length; i++){
        let peekRight = nums[i+1];
        let peekLeft = nums[i-1];
        if (peekRight !== nums[i] + 1 && peekLeft !== nums[i] - 1){
           result.push(`${nums[i]}`);
           startIdx++;
        } else if ( peekRight !== nums[i] + 1){
          result.push(`${nums[startIdx]}->${nums[i]}`);
          startIdx = i+1;
        }
      
    } 
   return result;
};
