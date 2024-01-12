// Runtime: 0 ms (Top 100.0%) | Memory: 2.10 MB (Top 33.33%)

impl Solution {
    pub fn find_min_fibonacci_numbers(k: i32) -> i32 {
        let mut nums: Vec<i32> = vec![0,1];
        loop {
            let n = nums.len();
            let last = nums[n-1];
            let pre = nums[n-2];
            let now = pre + last;
            if now > k {
                break;
            }
            nums.push(now);
        }

        let mut p: usize = nums.len()-1;
        let mut remain: i32 = k;
        let mut answer: i32 = 0;
        while remain > 0 {
            if remain >= nums[p] {
                remain -= nums[p];
                answer += 1;
            } else {
                p -= 1;
            }
        }
        answer
    }
}
