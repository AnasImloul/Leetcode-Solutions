// Runtime: 11 ms (Top 83.3%) | Memory: 2.38 MB (Top 25.0%)

impl Solution {
    pub fn largest_divisible_subset(nums: Vec<i32>) -> Vec<i32> {
        if nums.len() <= 1 {
            return nums;
        }
        let mut nums: Vec<i32> = nums;
        nums.sort();
        let mut ans: Vec<(usize, i32)> = Vec::new();
        
        let mut max: i32 = 0;
        let mut idx_ans: usize = 0;
        
        for i in 0..nums.len() {
            ans.push((i, 1));
            for j in 0..i {
                if nums[i] % nums[j] == 0 && ans[i].1 <= ans[j].1 {
                    ans[i].0 = j;
                    ans[i].1 = ans[j].1 + 1;
                    
                    if max < ans[i].1 {
                        max = ans[i].1;
                        idx_ans = i;
                    }
                }
            }
        }
        
        let mut result: Vec<i32> = Vec::new();
        let mut idx = idx_ans;
        
        while ans[idx].1 > 1 {
            result.push(nums[idx]);
            idx = ans[idx].0;
        }
        result.push(nums[idx]);
        
        result
    }
}