var minIncrementForUnique = function(nums) {
  let ans = 0, arr = nums.sort((a, b) => a - b);

  for (let i = 0; i < arr.length; i++) {
    if (arr[i] === arr[i + 1]) {
      arr[i + 1]++;
      ans++;
    }
    else if (arr[i] > arr[i + 1]) {
      if(arr[i] - arr[i - 1] === 1){
        ans += arr[i] - arr[i + 1] + 1
        arr[i + 1] += arr[i] - arr[i + 1] + 1;
      }
    }
  }

  return ans;
};