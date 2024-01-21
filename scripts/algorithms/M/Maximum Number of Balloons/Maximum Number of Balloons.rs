// Runtime: 0 ms (Top 100.0%) | Memory: 2.10 MB (Top 53.33%)

impl Solution {
    pub fn max_number_of_balloons(text: String) -> i32 {
        use std::collections::HashMap;
        
        let mut counter: HashMap<char, i32> = "balloon".chars().map(|c| (c, 0)).collect();

        text.chars().for_each(|c| {
            counter.entry(c).and_modify(|e| *e += 1);
        });

        counter
            .iter()
            .map(|(&c, &num)| num / if "lo".contains(c) { 2 } else { 1 })
            .min()
            .unwrap()
    }
}
