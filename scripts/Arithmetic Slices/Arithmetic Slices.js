/**
 * @param {number[]} nums
 * @return {number}
 */
var numberOfArithmeticSlices = function(nums) {
    nums.push(-2000)
    let count = 0  
    let dist = nums[1]-nums[0]
    let start = 0
    
    for (let i = 1; i < nums.length; i++) {
        if (nums[i]-nums[i-1] !== dist) {
            
            let len =  i - start
            start = i-1
            dist = nums[i] - nums[i-1]
            
            // count the length of each largest AS and add to sum 
            // of len = 5 => the number of sub AS = 1 (len = 5) + 2 (len = 4) + 3 (len = 3)
            for (let k = 3; k <=len; k++) {
                count += len - k + 1
            }
            
        }
    }
    
    return count
};
