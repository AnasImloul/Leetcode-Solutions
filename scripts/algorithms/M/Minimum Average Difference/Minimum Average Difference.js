// Runtime: 83 ms (Top 27.27%) | Memory: 65.10 MB (Top 27.27%)

/**
 * @param {number[]} nums
 * @return {number}
 */
var minimumAverageDifference = function(nums) {
    let firstSum = 0;
    let lastSum = 0;
    
    for(let num of nums) lastSum+=num;
    
    let minAvg = Number.POSITIVE_INFINITY;
    let minAvgIndex = 0;

    for(let i=0; i<nums.length; i++){
        firstSum+=nums[i];
        lastSum-=nums[i];

        if(i !== nums.length-1)
            currAvg = Math.abs(Math.floor(firstSum/(i+1))-Math.floor(lastSum/(nums.length-i-1)));
        else
            currAvg = Math.abs(Math.floor(firstSum/(i+1)));

        if(currAvg < minAvg){
            minAvg = currAvg;
            minAvgIndex = i;
        } 
    }

    return minAvgIndex;
};
