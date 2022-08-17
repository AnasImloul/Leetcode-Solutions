/**
 * @param {number[]} nums
 * @return {number}
 */
var countMaxOrSubsets = function(nums) {
    
    let n = nums.length;
    let len = Math.pow(2, n);
    let ans = 0;
    let hash = {};
    
    for (let i = 0; i < len; i++) { 
        let tmp = 0;
        for (let j = 0; j < n; j++) { 
            if(i & (1 << j)) {
                tmp |= nums[j];
            }
        }
        if (hash[tmp]) {
            hash[tmp] += 1;
        } else {
            hash[tmp] = 1;
        }
        ans = Math.max(ans, tmp);
    }
    
    return hash[ans];
};
