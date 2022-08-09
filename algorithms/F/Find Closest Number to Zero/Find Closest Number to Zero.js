//Solution 1
var findClosestNumber = function(nums) {
    
    let pos = Infinity;
    let neg = -Infinity;
    
    for(let i = 0; i < nums.length; i++) {
        
        if( nums[i] > 0 ){
           if( pos > nums[i] ) 
               pos = nums[i];               
        } else {
            if( neg < nums[i] )
                neg = nums[i];
        } 
    }
    
    if( -neg < pos ) {
       return neg;
    }
    
    return pos;   
};

//Solution 2
var findClosestNumber = function(nums) {
    
    let result = nums[0];
    
    for(let i=1; i<nums.length; i++) {
        
        let mod = Math.abs(nums[i]);
        
        if( Math.abs(result)>mod ) {            
            result = nums[i]
        }
        
        if( Math.abs(result) == mod ) {
            if( result<nums[i] ) {
                result = nums[i];
            }
        }
    }
    
    return result;    
};
