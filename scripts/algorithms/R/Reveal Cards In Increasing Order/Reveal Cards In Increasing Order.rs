// Runtime: 1 ms (Top 71.43%) | Memory: 2.10 MB (Top 71.43%)

impl Solution {
    pub fn deck_revealed_increasing(deck: Vec<i32>) -> Vec<i32> {
        use std::collections::VecDeque;
        let mut deck = deck;
        deck.sort();
        let mut solution: VecDeque<i32> = VecDeque::new();
        deck.iter().rev().for_each(|v| {
            solution.push_front(*v);
            let temp = solution.pop_back().unwrap();
            solution.push_front(temp);
        });
        let temp = solution.pop_front().unwrap();
        solution.push_back(temp);
        Vec::from(solution)
    }
}
