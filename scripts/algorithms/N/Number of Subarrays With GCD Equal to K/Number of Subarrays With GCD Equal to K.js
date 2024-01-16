// Runtime: 65 ms (Top 88.89%) | Memory: 41.70 MB (Top 88.89%)

/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var subarrayGCD = function(nums, k) {
  let res = 0;
  let left = 0;
  let cur = nums[0], right = -1, pos = -1;
  for (let i = 0; i < nums.length; i++) {
    if (nums[i] % k !== 0) {
      left = i + 1;
      cur = nums[i+1];
    } else {
      cur = gcd(cur, nums[i]);
      if (cur === k) {
        for (let j = i; j >= pos; j--) {
          if (gcd(nums[i], nums[j]) === k) {
            right = j;
            cur = nums[i];
            pos = i;
            break;
          }
        }
      }
      res += Math.max(0, right - left + 1);
    }
  }
  return res;
};

const gcd = (a, b) => {
  if (!b) {
    return a;
  }
  return gcd(b, a % b);
}
