// Runtime: 3 ms (Top 100.0%) | Memory: 2.26 MB (Top 100.0%)

impl Solution {
    pub fn min_operations(nums: Vec<i32>) -> i32 {
        if nums.contains(&1) {
            return nums.iter().filter(|n| **n != 1).count() as i32;
        }
        let mut distance: i32 = -1;
        let mut i = 0;
        while i < nums.len() {
            let mut cur_num = nums[i];
            for j in i+1..nums.len() {
                let g = Self::gcd(nums[j], cur_num);
                if g == nums[j] {
                    i = j-1;
                    break;
                }
                if g == 1 {
                    if distance == -1 || distance > (j - i) as i32 {
                        distance = (j - i) as i32;
                        break;
                    }
                } else {
                    cur_num = g;
                }
            }
            i += 1;
        }
        
        if distance == -1 {
            -1
        } else {
            distance - 1 + nums.len() as i32
        }
    }

    fn gcd(a: i32, b: i32) -> i32 {
        let (mut a, mut b) = (a, b);
        while b != 0 {
            let temp = b;
            b = a % b;
            a = temp;
        }
        a
    }
}