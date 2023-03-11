var countRangeSum = function(nums, lower, upper) {
  let preSum = Array(nums.length + 1).fill(0);
  let count = 0;

  // create preSum array, use preSum to check the sum range
  for (let i = 0; i < nums.length; i++) {
      preSum[i + 1] = preSum[i] + nums[i];
  }

  const sort = function(preSum) {
      if (preSum.length === 1) return preSum;

      let mid = Math.floor(preSum.length / 2);
      let left = sort(preSum.slice(0, mid));
      let right = sort(preSum.slice(mid))

      return merge(left, right);
  }

  const merge = function(left, right) {
      let start = 0;
      let end = 0;

      for (let i = 0; i < left.length; i++) {
          // all elements before start index, after subtracting left[i] are less than lower, which means all elements after start index are bigger or equal than lower
          while (start < right.length && right[start] - left[i] < lower) {
              start++;
          }
          // similarly, all elements before end index are less or euqal then upper
          while (end < right.length && right[end] - left[i] <= upper) {
              end++;
          }

          // since the initial values of start and end are the same, and upper >= lower, so end will >= start too, which means the rest of the end minus start element difference will fall between [lower, upper].
          count += end - start;
      }

      let sort = [];
      while (left.length && right.length) {
          if (left[0] <= right[0]) {
              sort.push(left.shift());
          } else {
              sort.push(right.shift());
          }
      }

      return [...sort, ...left, ...right];
  }

  sort(preSum);
  return count;
};