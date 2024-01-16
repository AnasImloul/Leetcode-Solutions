// Runtime: 52 ms (Top 97.87%) | Memory: 43.90 MB (Top 78.72%)

var smallestDistancePair = function(nums, k) {    
    nums.sort((a,b) => a - b);   
    let left = 0, right = nums[nums.length-1] - nums[0], mid = null, total = 0;    
    
    while (left < right) {
        mid = left + Math.floor((right - left) / 2);
    
        total = 0;
        for (var i = 0, j = 1; i < nums.length - 1 && total <= k; i++) {
            for ( ; j < nums.length && nums[j] - nums[i] <= mid; j++) {}
			total += j - i - 1; 
        }
        
        if (total >= k) {right = mid;}  
		else {left = mid+1;}
    }    
	
    return left;
};
