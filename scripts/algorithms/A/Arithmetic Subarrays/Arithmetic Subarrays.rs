// Runtime: 0 ms (Top 100.0%) | Memory: 2.20 MB (Top 46.15%)

impl Solution {
    pub fn check_arithmetic_subarrays(nums: Vec<i32>, l: Vec<i32>, r: Vec<i32>) -> Vec<bool> {
        let mut ans = Vec::new();

        for i in 0..l.len() {
            let left = l[i] as usize;
            let (min, max) = nums[left..=r[i] as usize].iter().fold(
                (i32::MAX, i32::MIN), |acc, x| (acc.0.min(*x), acc.1.max(*x)));
            if max == min { ans.push(true); continue };

            let N = r[i] - l[i];
            let d = (max - min) / N;
            if (max - min) % N != 0 { ans.push(false); continue };

            let mut visited = vec![false; N as usize + 1];
            if (0..=N as usize).all(|j| {
                if (nums[left+j] - min) % d != 0 || 
                visited[((nums[left+j] - min) / d) as usize] {
                    false
                } else {
                    visited[((nums[left+j] - min) / d) as usize] = true;
                    true
            }})  { ans.push(true) }
            else { ans.push(false) };
        }

        ans
    }
}
