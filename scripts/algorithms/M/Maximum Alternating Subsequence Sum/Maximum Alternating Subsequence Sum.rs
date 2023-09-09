// Runtime: 13 ms (Top 100.0%) | Memory: 3.60 MB (Top 50.0%)

impl Solution {
  pub fn max_alternating_sum(nums: Vec<i32>) -> i64 {
    let n = nums.len();
    let nums = nums.into_iter().map(|v| v as i64).collect::<Vec<i64>>();
    let mut a = nums[0];
    let mut b = 0;

    for i in 1..n {
      let v = nums[i];
      b = b.max(a-v);
      a = a.max(b+v);
    }
 
    a.max(b)
  }
}