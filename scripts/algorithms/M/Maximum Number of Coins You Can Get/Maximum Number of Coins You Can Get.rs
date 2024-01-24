// Runtime: 17 ms (Top 73.7%) | Memory: 3.20 MB (Top 44.07%)

impl Solution {
    pub fn max_coins(mut piles: Vec<i32>) -> i32 {
        let n = piles.len() / 3;
        piles.sort_unstable();
        piles.into_iter().skip(n).step_by(2).sum()
    }
}
