// Runtime: 129 ms (Top 64.8%) | Memory: 77.21 MB (Top 6.3%)

var maximumSubarraySum = function(nums, k) {
    
    let j = 0;
    let map = new Map();
    let sum = 0;
    let maxSum = 0;
    nums.forEach((value, i) => {
        // current sum
        sum += value;
        //currnet map values
        if(map.has(value)) {
            map.set(value, map.get(value) + 1);
        }
        else{
            map.set(value, 1);
        }
        
        //if subarray length becomes > k remove front element from previous window
        if(i - j >= k) {
            sum -= nums[j];
            if(map.get(nums[j]) > 1) map.set(nums[j], map.get(nums[j])-1);
            else map.delete(nums[j]);
            j++;
        }
        
        if(i - j + 1 ===  k) {
            if(map.size === k) {
                maxSum = Math.max(maxSum, sum);
            }
        }
       
    });
    return maxSum;
};