// Runtime: 98 ms (Top 67.73%) | Memory: 65.80 MB (Top 42.93%)

var checkSubarraySum = function(nums, k) {
    const n = nums.length;
    if(n < 2) {
        return false;
    }
    const map = new Map();
	
	// edge case - to handle sum % k === 0 and
	// if the first element of array is a multiple of k, condition 0 - (-1) = 1 > 1 wil fail (min length of subarray must be 2)
    map.set(0, -1);
    let sum = 0;
    
    for(let i = 0; i < n; ++i) {
        sum += nums[i];
        sum = sum % k;
		
		// handles min length of subarray must be 2
        if(map.has(sum) && i - map.get(sum) > 1) {
            return true;
        } else if(!map.has(sum)) {
            map.set(sum, i);
        }
    }
    return false;
}
