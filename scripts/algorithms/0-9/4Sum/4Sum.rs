// Runtime: 6 ms (Top 88.5%) | Memory: 2.18 MB (Top 54.8%)

use std::cmp::Ordering;

impl Solution {
    pub fn four_sum(nums: Vec<i32>, target: i32) -> Vec<Vec<i32>> {
        let mut combinations: Vec<Vec<i32>> = vec![];
        let len = nums.len();

        if len < 4 { return combinations; }  // can't have multiple of 4

        // Convert the Vec<i32> to Vec<i64> to handle large numbers.
        let mut nums: Vec<i64> = nums.into_iter().map(|x| x as i64).collect();
        let target = target as i64;
        
        nums.sort_unstable(); // sort to allow left/right crawling

        for i in 0..len - 3 {
            if nums[i] * 4 > target {
                break;  // no more solutions can be found if left most index (i) cannot divide/4 evenly or less than target
            }         // considering all numbers right of (i) are either equal or larger!

            // traverse duplicates
            if i > 0 && nums[i] == nums[i - 1] { continue; }  

            for j in i + 1..len - 2 {
                if nums[j] * 3 > target - nums[i] {
                    continue;  // continue j loop if second left most index (j) cannot divide/3 evenly or less than target - i
                }

                // traverse duplicates
                if j > i + 1 && nums[j] == nums[j - 1] { continue; }

                let (mut left, mut right) = (j + 1, len - 1);

                while left < right {
                    let cur_val = nums[i] + nums[j] + nums[left] + nums[right];
                    match cur_val.cmp(&target) {
                        Ordering::Equal => {
                            // if equal, push solution
                            combinations.push(vec![nums[i] as i32, nums[j] as i32, nums[left] as i32, nums[right] as i32]);

                            // pull left and right inwards
                            left += 1;
                            right -= 1;

                            // then traverse any duplicates
                            while left < right && nums[left] == nums[left - 1] {
                                left += 1;
                            }
                            while left < right && nums[right] == nums[right + 1] {
                                right -= 1;
                            }
                        }
                        Ordering::Less => left += 1,     // if sum is less move left to find a larger sum
                        Ordering::Greater => right -= 1, // if sum is greater move right to find a smaller sum
                    }
                }
            }
        }
        combinations
    }
}