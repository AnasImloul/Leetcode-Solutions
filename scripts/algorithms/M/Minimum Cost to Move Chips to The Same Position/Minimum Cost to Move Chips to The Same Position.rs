// Runtime: 0 ms (Top 100.0%) | Memory: 2.20 MB (Top 20.0%)

impl Solution {
    pub fn min_cost_to_move_chips(position: Vec<i32>) -> i32 {
        let odd = position.iter().filter(|&p| p % 2 == 1).count();
        std::cmp::min(odd, position.len() - odd) as i32
    }
}