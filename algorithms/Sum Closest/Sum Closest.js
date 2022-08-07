/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var threeSumClosest = function(nums, target) {
    // TC : O(n^2)
    const n = nums.length;
    nums.sort((x, y) => x - y);
    var result = nums[1]+nums[0]+nums[2]
    
    for(var i = 0 ; i< n-1 ; i++)
    {
        var low = i+1;
        var high = n-1;
        
        while(low < high){
            var sum = nums[i] + nums[low] + nums[high];
            
            if(target == sum)
                return sum;
            
            if(Math.abs(sum-target) < Math.abs(result - target)){
                result = sum;
            }
            
            if(sum > target)
                high -= 1;
            
            else
                low += 1;
            
        }
    }
    return result;
};

