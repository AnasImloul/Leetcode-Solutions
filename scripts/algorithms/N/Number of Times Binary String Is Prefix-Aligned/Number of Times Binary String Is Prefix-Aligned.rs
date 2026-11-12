// Runtime: 6 ms (Top 75.0%) | Memory: 2.51 MB (Top 25.0%)

impl Solution {
  pub fn num_times_all_blue(flips: Vec<i32>) -> i32 {
    let n = flips.len();
    let mut max = 0;
    let mut result = 0;
    for i in 1..=n {
      max = max.max(flips[i-1] as usize);
      if max == i {
        result += 1;
      }
    }

    result
  }
}