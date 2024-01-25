// Runtime: 115 ms (Top 75.0%) | Memory: 6.30 MB (Top 100.0%)

impl Solution {
    pub fn min_cost(max_time: i32, edges: Vec<Vec<i32>>, passing_fees: Vec<i32>) -> i32 {
        fn solve(dp: &mut Vec<Vec<i32>>, time: i32, adj: &Vec<Vec<(i32, i32)>>, v: i32, pass: &Vec<i32>) -> i32 {
            if time < 0 {
                return std::i32::MAX;
            }
            let n = pass.len() as i32;
            if v == n - 1 {
                return pass[v as usize];
            }
            if dp[v as usize][time as usize] != -1 {
                return dp[v as usize][time as usize];
            }
            let mut cost = std::i32::MAX;
            for x in &adj[v as usize] {
                let u = x.0;
                let temp = x.1;
                if temp <= time {
                    let sol = solve(dp, time - temp, adj, u, pass);
                    cost = cost.min(sol);
                }
            }
            if cost == std::i32::MAX {
                dp[v as usize][time as usize] = std::i32::MAX;
                return std::i32::MAX;
            }
            dp[v as usize][time as usize] = cost + pass[v as usize];
            dp[v as usize][time as usize]
        }

        let mut dp = vec![vec![-1; 1001]; 1001];
        let n = passing_fees.len();
        let mut adj = vec![vec![]; n];
        for edge in edges.iter() {
            let x = edge[0] as usize;
            let y = edge[1] as usize;
            let time = edge[2];
            adj[x].push((y as i32, time));
            adj[y].push((x as i32, time));
        }
        let ans = solve(&mut dp, max_time, &adj, 0, &passing_fees);
        if ans == std::i32::MAX {
            return -1;
        }
        ans
    }
}
