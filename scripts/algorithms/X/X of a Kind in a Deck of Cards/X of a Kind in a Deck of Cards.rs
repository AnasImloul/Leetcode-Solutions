// Runtime: 2 ms (Top 90.0%) | Memory: 2.20 MB (Top 50.0%)

use std::collections::HashMap;

impl Solution {

  fn gcd(mut a: i32, mut b: i32) -> i32 {
    while b > 0 {
      let tmp = a;
      a = b;
      b = tmp % b;
    }
    return a;
  }

  pub fn has_groups_size_x(deck: Vec<i32>) -> bool {
    let mut data = HashMap::new();
    for v in deck {
      *data.entry(v).or_insert(0) += 1;
    }

    let mut val = 0;
    for (_, v) in data {
      val = Self::gcd(v, val);
    }
    return val > 1;
  }
}
