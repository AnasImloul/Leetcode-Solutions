var waysToSplit = function(nums) {
    const mod = 1000000007;
    const lastIndex = nums.length - 2;
    const total = nums.reduce((sum, num) => sum + num)

    let midLeftPtr = -1;
    let midRightPtr = -1;
    
    let leftSum = 0;
    let midLeftSum = 0;
    let midRightSum = 0;
    
    let numWaysToSplit = 0;
    
    for (let leftPtr = 0; leftPtr < nums.length; leftPtr++) {
        leftSum += nums[leftPtr];        
        midLeftSum -= nums[leftPtr];
        midRightSum -= nums[leftPtr];

       // find the first index that satisfies the middle sum
	   // being greater than or equal to the left sum
        while (midLeftPtr <= lastIndex && 
               (midLeftPtr <= leftPtr || midLeftSum < leftSum)) {
            midLeftPtr++;
            midLeftSum += nums[midLeftPtr]
        }

        // find the first index that makes the middle sum greater than the right sum
        while (midRightPtr <= lastIndex && 
               (midLeftPtr > midRightPtr || midRightSum <= total - midRightSum - leftSum)) {
            midRightPtr++
            midRightSum += nums[midRightPtr]
        }
        numWaysToSplit = (numWaysToSplit + midRightPtr - midLeftPtr) % mod;
    }
    return numWaysToSplit
};
