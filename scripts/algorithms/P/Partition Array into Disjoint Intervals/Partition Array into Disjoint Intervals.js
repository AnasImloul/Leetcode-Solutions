/**
 * @param {number[]} nums
 * @return {number}
 */
var partitionDisjoint = function(nums) {
    let n = nums.length;
    let leftMax = Array(n).fill(0), rightMin = Array(n).fill(0);
    let left = 0, right = n- 1;
    
    for(let i = 0, j = n - 1;i<n, j>=0 ;i++,j--){
        leftMax[i] = Math.max(nums[i], !i ? -Infinity : leftMax[i-1]);
        rightMin[j] = Math.min(nums[j], j === n - 1 ? Infinity : rightMin[j+1]);
    }
    
    for(let i = 0;i<n-1;i++){
        if(leftMax[i] <= rightMin[i+1]){
            return i + 1;
        }
    }
 
};
