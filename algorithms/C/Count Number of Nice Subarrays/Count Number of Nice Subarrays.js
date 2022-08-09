/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var numberOfSubarrays = function(nums, k) {
    const len = nums.length;
    const pre = new Array(len).fill(-1);
    const post = new Array(len).fill(len);
    
    let lastOcc = -1;
    for(let i = 0; i < len; i++) {
        pre[i] = lastOcc;
        if(nums[i] & 1) lastOcc = i;
    }
    lastOcc = len;
    for(let i = len - 1; i >= 0; i--) {
        post[i] = lastOcc;
        if(nums[i] & 1) lastOcc = i;
    }
    
    let l = 0, r = 0, oddCount = 0;
    
    let ans = 0;
    
    for(; r < len; r++) {
        while(l < len && !(nums[l] & 1)) l++;
        if(nums[r] & 1) oddCount++;
        
        if(oddCount == k) {
            let leftCount = l - pre[l];
            let rightCount = post[r] - r;
            ans += leftCount * rightCount;
            
            oddCount--;
            l++;
        }
    }
    
    return ans;
};
