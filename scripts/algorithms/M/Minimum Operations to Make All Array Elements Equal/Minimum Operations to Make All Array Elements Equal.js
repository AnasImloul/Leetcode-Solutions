// Runtime: 232 ms (Top 88.89%) | Memory: 76.80 MB (Top 77.78%)

var minOperations = function(nums, queries) {
  nums.sort((a, b) => a - b);
  let n = nums.length;
  let left = [...nums], right = [...nums];
  for (let i = 1; i < n; i++) left[i] += left[i - 1];
  for (let i = n - 2; i >= 0; i--) right[i] += right[i + 1];
  let ans = [];
  for (let query of queries) {
    let splitIndex = getSplitIndex(query);
    let leftDiff = splitIndex > 0 ? query * splitIndex - left[splitIndex - 1] : 0;
    let rightDiff = splitIndex < n ? right[splitIndex] - query * (n - splitIndex) : 0;
    ans.push(leftDiff + rightDiff);
  }
  return ans;
  
  function getSplitIndex(query) {
    let low = 0, high = n - 1;
    while (low < high) {
      let mid = Math.floor((low + high) / 2);
      if (nums[mid] >= query) high = mid;
      else low = mid + 1;
    }
    return nums[low] >= query ? low : n;
  }
};
