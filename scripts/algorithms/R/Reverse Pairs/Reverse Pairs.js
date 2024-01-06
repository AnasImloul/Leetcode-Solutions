// Runtime: 150 ms (Top 60.29%) | Memory: 85.20 MB (Top 11.76%)

/**
 * @param {number[]} nums
 * @return {number}
 */
var reversePairs = function(nums) {
  let numReversePairs = 0; 
  helper(nums);
  return numReversePairs;
  
  function helper(nums) {
    if (nums.length <= 1) return nums;   
    const length = nums.length;
    const left = helper(nums.slice(0, Math.floor(length/2)));
    const right = helper(nums.slice(Math.floor(length/2)));    
    return merge(left, right);    
  }
  
  function merge(left, right) {
    const nums_sorted = [];
    let leftIndex = 0;
    let rightIndex = 0;  
    while(leftIndex < left.length && rightIndex < right.length) {
      if (left[leftIndex] > 2 * right[rightIndex]) {
        numReversePairs += (left.length - leftIndex);
        rightIndex++;
      } else {
        leftIndex++;
      }
    }    
    leftIndex = 0;
    rightIndex = 0;
    while (leftIndex < left.length && rightIndex < right.length) {
      if (left[leftIndex] < right[rightIndex]) {
        nums_sorted.push(left[leftIndex]);
        leftIndex++;
      } else {
        let cur = leftIndex;
        nums_sorted.push(right[rightIndex]);
        rightIndex++;
      }
    }
    while (leftIndex < left.length) {
      nums_sorted.push(left[leftIndex]);
      leftIndex++;
    }
    while (rightIndex < right.length) {
      nums_sorted.push(right[rightIndex]);
      rightIndex++;
    }
    return nums_sorted;
  }
  
};
