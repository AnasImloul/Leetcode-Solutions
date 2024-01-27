// Runtime: 11 ms (Top 66.67%) | Memory: 3.20 MB (Top 100.0%)

impl Solution {
    pub fn min_operations(nums: Vec<i32>) -> i32 {
        let mut result = 0;
        let mut max = 0;
        for &num in nums.iter() {
            let mut cv = num;
            let mut temp = 0;
            while cv > 0 {
                if cv % 2 == 0 {
                    cv /= 2;
                    temp += 1;
                } else {
                    cv -= 1;
                    result += 1;
                }
            }
            max = max.max(temp);
        }

        result + max
    }
}
