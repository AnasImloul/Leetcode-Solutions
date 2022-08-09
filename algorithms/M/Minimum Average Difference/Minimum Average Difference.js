
```/**
 * @param {number[]} nums
 * @return {number}
 */
 var minimumAverageDifference = function(nums) {
    if (nums.length == 1) return 0;
    let mins = 100000, resultIndex, leftTotal = 0;
    let rightTotal = nums.reduce((a,b)=>a + b);
    let numLength = nums.length;
    nums.forEach((data, index)=> {
        leftTotal += data;
        rightTotal -= data;
        let currentAverageDiff = Math.abs(Math.floor(leftTotal/(index+1)) - Math.floor(rightTotal/(numLength-index-1) || 0));
        if (currentAverageDiff < mins) {
            resultIndex = index;
            mins = currentAverageDiff;
        }
    });
    return resultIndex;
};