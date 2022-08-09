/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var search = function(nums, target) {
    
    let low=0;
    let high=nums.length-1;
    
    if(target<nums[0] || target>nums[high]){
        return -1;
    }
    
    while(low<=high) {
        
        mid=Math.floor((low+high)/2);
        
        if (nums[mid]==target){
            return mid;
        }
        else{
            
            if(target>nums[mid]){
                low=mid+1;
                
            }
            else{
                high=mid-1;
            }
        }
    }
    
    return -1;
    
};
