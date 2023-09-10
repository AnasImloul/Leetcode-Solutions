// Runtime: 33 ms (Top 40.0%) | Memory: 5.76 MB (Top 20.0%)

use std::cmp::Ordering;
impl Solution {
  pub fn match_players_and_trainers(players: Vec<i32>, trainers: Vec<i32>) -> i32 {
    let mut memo = vec![];
    for v in players {
      memo.push((v,0));
    }
    for v in trainers {
      memo.push((v,1));
    }

    let mut result = 0;
    let mut a = 0;
    memo.sort_by(|a,b| {
      let v = a.0.cmp(&b.0);
      if v == Ordering::Equal {
        a.1.cmp(&b.1)
      } else {
        v
      }
    });

    for (_,t) in memo {
      if t == 1 {
        if 0 < a {
          a -= 1;
          result += 1;
        }
      } else {
        a += 1;
      }
    }

    result
  }
}