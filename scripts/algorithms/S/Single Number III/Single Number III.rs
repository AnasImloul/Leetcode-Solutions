// Runtime: 1 ms (Top 75.0%) | Memory: 2.20 MB (Top 90.0%)

impl Solution {
    pub fn single_number(nums: Vec<i32>) -> Vec<i32> {
        let xor = nums.iter().fold(0, |acc, x| acc ^ x);
        let r = xor & !(xor - 1);
        let mut answer = vec![0, 0];
        for n in nums.iter() {
            if n & r == 0 {
                answer[0] ^= *n;
            } else {
                answer[1] ^= *n;
            }
        }
        answer
    }
}
