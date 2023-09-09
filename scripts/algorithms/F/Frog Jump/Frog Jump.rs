// Runtime: 63 ms (Top 17.4%) | Memory: 3.93 MB (Top 46.3%)

use std::collections::{HashSet, VecDeque};
impl Solution {
    pub fn can_cross(stones: Vec<i32>) -> bool {
        if stones[0] != stones[1] - 1 { return false }

        let mut queue = VecDeque::from([(stones[1], 1)]);
        let mut visited = HashSet::from([(stones[1], 1)]);

        let valid_stones = |stone: i32| {
            let (min, max) = (1.max(stone - 1), stone + 2);
            (min..max)
                .filter_map(|stone| stones.binary_search(&stone).ok())
                .map(|idx| stones[idx])
        };

        while let Some((loc, leap)) = queue.pop_front() {
            if Some(&loc) == stones.last() { return true }

            for stone in valid_stones(loc + leap) {
                let path = (stone, stone - loc);
                if visited.insert(path) { queue.push_back(path) }
            }
        }

        false
    }
}