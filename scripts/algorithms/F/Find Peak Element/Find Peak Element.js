// Runtime: 63 ms (Top 93.57%) | Memory: 42 MB (Top 69.12%)
/**
 * @param {number[]} nums
 * @return {number}
 */
var findPeakElement = function(nums) {
  if(nums.length === 1) return 0;

  const recursion = (startIndex, endIndex) => {
     const midIndex = Math.floor((startIndex + endIndex)/2);

     if (startIndex === endIndex) return startIndex;
     if (startIndex + 1 === endIndex) {
        return nums[endIndex] >= nums [startIndex] ? endIndex : startIndex;
     }

     if(nums[midIndex] > nums[midIndex-1] && nums[midIndex] > nums[midIndex+1]) return midIndex;
     if(nums[midIndex] > nums[midIndex-1] && nums[midIndex] < nums[midIndex+1]) return recursion(midIndex + 1, endIndex);
     if(nums[midIndex] < nums[midIndex-1] && nums[midIndex] > nums[midIndex+1]) return recursion(startIndex, midIndex - 1);
     if(nums[midIndex] < nums[midIndex-1] && nums[midIndex] < nums[midIndex+1])
        return nums[midIndex-1] > nums[midIndex+1] ? recursion(startIndex, midIndex - 1) : recursion(midIndex + 1, endIndex);

  }

  return recursion(0, nums.length - 1);
};