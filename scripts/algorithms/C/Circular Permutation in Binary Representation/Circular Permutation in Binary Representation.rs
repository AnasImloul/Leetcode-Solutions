// Runtime: 11 ms (Top 71.43%) | Memory: 2.80 MB (Top 14.29%)

use std::collections::*;

impl Solution {
  pub fn circular_permutation(n: i32, start: i32) -> Vec<i32> {
      let limit = 1 << n;
      let mut que = VecDeque::new();
      for i in 0..limit {
        que.push_back(i ^ (i >> 1));
      }
      while que[0] != start {
        let v = que.pop_front().unwrap();
        que.push_back(v);
      }
      que.into_iter().collect::<Vec<i32>>()
  }
}
