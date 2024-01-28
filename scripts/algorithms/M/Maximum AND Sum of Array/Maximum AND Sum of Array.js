// Runtime: 86 ms (Top 100.0%) | Memory: 53.30 MB (Top 25.0%)

/**
 * @param {number[]} nums
 * @param {number} numSlots
 * @return {number}
 */
var maximumANDSum = function(nums, numSlots) {
    let memo=[],mask=0;
    let ans =  dp(0,0);
    return ans;
    
    function dp(i,mask){
        let max = 0,sum;
        if(memo[mask]!==undefined){
            return memo[mask];
        }
        if(i===nums.length){
            return 0;
        }
        for(let s=1,maskBit=1;s<=numSlots;s++,maskBit*=3){
            if(Math.floor(mask/maskBit)%3<2){
                sum = (nums[i]&s)+dp(i+1,mask+maskBit);
                max = Math.max(sum,max);
            }
        }
        memo[mask]=max;
        return memo[mask];
    }
};
