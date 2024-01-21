// Runtime: 0 ms (Top 100.0%) | Memory: 2.20 MB (Top 28.33%)

impl Solution {
    pub fn sort_array_by_parity(nums: Vec<i32>) -> Vec<i32> {
        let mut even = Vec::new();
        let mut odd = Vec::new();

        for num in nums {
            if num % 2 == 0 {
                even.push(num);
            } else {
                odd.push(num);
            }
        }

        even.extend(odd);
        even
    }
}

