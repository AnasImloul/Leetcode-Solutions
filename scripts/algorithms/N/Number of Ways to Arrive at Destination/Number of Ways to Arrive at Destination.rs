// Runtime: 10 ms (Top 100.0%) | Memory: 3.70 MB (Top 100.0%)

use std::collections::*;

const MOD:usize = 1_000_000_007;
const INF:usize = 1_000_000_000_000_000;
fn dfs(memo:&Vec<(usize,HashSet<usize>)>, dp:&mut Vec<usize>, i:usize) -> usize {
  if dp[i] == INF {
    let mut temp = 0;
    for &j in &memo[i].1 {
      temp += dfs(memo, dp, j);
      temp %= MOD;
    }
    dp[i] = temp;
  }

  dp[i]
}

impl Solution {
  pub fn count_paths(n: i32, roads: Vec<Vec<i32>>) -> i32 {
    let n = n as usize;
    let mut g = vec![vec![];n];
    for arr in roads {
      let a = arr[0] as usize;
      let b = arr[1] as usize;
      let c = arr[2] as usize;
      g[a].push((b,c));
      g[b].push((a,c));
    }

    
    let mut memo = vec![(INF,HashSet::new());n];
    memo[0].0 = 0;
    let mut stack = vec![(0,0)];
    while !stack.is_empty() {
      let mut new_stack = vec![];
      while let Some((ci,cv)) = stack.pop() {
        for &(ni, v) in &g[ci] {
          let nv = cv + v;
          if nv < memo[ni].0 {
            memo[ni].1 = HashSet::new();
            memo[ni].1.insert(ci);
            memo[ni].0 = nv;
            new_stack.push((ni,nv));
          } else if nv == memo[ni].0 {
            memo[ni].1.insert(ci);
          }
        }
      }
      stack = new_stack;
    }

    let mut result = vec![INF;n];
    result[0] = 1;
    
    dfs(&memo, &mut result, n-1) as i32
  }
}
