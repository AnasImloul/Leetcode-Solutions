// Runtime: 6 ms (Top 100.0%) | Memory: 9.30 MB (Top 100.0%)

impl Solution {
  pub fn find_the_longest_substring(s: String) -> i32 {
    let s = s.chars().collect::<Vec<char>>();
    let n = s.len();
    let limit = 1 << 5;
    let mut memo = vec![vec![];limit];
    
    let dict = ['a','i','u','e','o'];
    let mut now = 0;
    for i in 0..n {
      memo[now].push(i);
      for j in 0..5 {
        if s[i] == dict[j] {
          let v = 1 << j;
          now ^= v;
          break
        }
      }
    }
    memo[now].push(n);

    let mut result = 0;
    let mut i = 0;
    for arr in memo {
      if arr.len() >= 2 {
        result = result.max(arr[arr.len()-1] - arr[0]);
      }
      i += 1;
    }
    
    result as i32
  }
}
