// Runtime: 2 ms (Top 80.0%) | Memory: 2.30 MB (Top 80.0%)

impl Solution {
    pub fn flipgame(fronts: Vec<i32>, backs: Vec<i32>) -> i32 {
        let mut nums = [0; 2000];
        for (f,b) in fronts.into_iter().zip(backs) {
            if f == b {
                nums[f as usize - 1] |= 2;
            } else {
                nums[f as usize - 1] |= 1;
                nums[b as usize - 1] |= 1;
            }
        }
        nums.into_iter()
          .position(|&x| x == 1)
          .map_or(0, |i| i as i32 + 1)
    }
}