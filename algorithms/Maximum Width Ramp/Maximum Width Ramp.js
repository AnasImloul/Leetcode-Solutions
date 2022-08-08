var maxWidthRamp = function(nums) {
  let stack = [], ans = 0;
  for (let i = 0; i < nums.length; i++) {
    let index = lower_bound(stack, i);
    ans = Math.max(ans, i - index);
    if (!stack.length || nums[i] < nums[stack[stack.length - 1]]) stack.push(i);
  }
  return ans;
  
  function lower_bound(arr, index) {
    if (!arr.length) return index;
    let low = 0, high = arr.length - 1;
    while (low < high) {
      let mid = Math.floor((low + high) / 2);
      if (nums[arr[mid]] <= nums[index]) high = mid;
      else low = mid + 1;
    }
    return nums[arr[low]] <= nums[index] ? arr[low] : index;
  }
};
