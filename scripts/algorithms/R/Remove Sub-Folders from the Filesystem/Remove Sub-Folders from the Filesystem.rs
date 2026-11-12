// Runtime: 77 ms (Top 9.09%) | Memory: 12.30 MB (Top 9.09%)

use std::collections::*;

impl Solution {
  pub fn remove_subfolders(mut folder: Vec<String>) -> Vec<String> {
    folder.sort();
    let mut set = HashSet::new();
    let mut result = vec![];
    for s in folder {
      let sc = s.chars().collect::<Vec<char>>();
      let n = s.len();
      let mut exist = true;
      for i in 0..n-1 {
        if sc[i] == '/' {
          if set.contains(&sc[0..i]) {
            exist = false;
            break
          }
        }
      }

      if exist {
        result.push(s)
      }
      set.insert(sc);
    }
    result
  }
}
