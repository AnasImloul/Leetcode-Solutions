/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var waysToPartition = function(nums, k) {
    let totalSum=nums.reduce((acc, curr) => acc+curr)
    let left=0;
    let rightDiff={}
    let leftDiff={}
    
    for(let i=0; i<nums.length-1; i++) {
        left+=nums[i]
        const right=totalSum-left
        if(rightDiff[left-right]) rightDiff[left-right]++
        else rightDiff[left-right]=1
    }

    let maxPartition=rightDiff[0] ? rightDiff[0] : 0
    left=0
    for(let i=0; i<nums.length; i++) {
        left+=nums[i]
        let diff=k-nums[i]
        const right=totalSum-left
        let leftVal=leftDiff[`${diff}`] ? leftDiff[`${diff}`] : 0
        let rightVal=rightDiff[`${-diff}`] ? rightDiff[`${-diff}`] : 0
        
        maxPartition=Math.max(maxPartition, leftVal+rightVal)
        if(leftDiff[left-right]) leftDiff[left-right]++
        else leftDiff[left-right]=1
        
        rightDiff[left-right]--

    }
    
    return maxPartition

};
```