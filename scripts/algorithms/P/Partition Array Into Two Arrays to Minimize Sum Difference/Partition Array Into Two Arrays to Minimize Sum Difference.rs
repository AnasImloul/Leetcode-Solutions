// Runtime: 170 ms (Top 100.0%) | Memory: 2.30 MB (Top 100.0%)

impl Solution {
    pub fn minimum_difference(nums: Vec<i32>) -> i32 {
        let n = nums.len() / 2;
        let mut cache_left: Vec<Vec<i32>> = vec![vec![]; n + 1];
        let s: i32 = nums.iter().sum();
        for i in 0..(1 << n) as u32 {
            let len_left = i.count_ones() as usize;
            let sum_left = Solution::subsum(i, &nums[..n]);
            cache_left[len_left].push(s - 2 * sum_left);
        }

        cache_left.iter_mut().for_each(|x| x.sort_unstable());

        let mut min_absdiff = i32::max_value();
        for i in 0..(1 << n) as u32 {
            let sum_right = Solution::subsum(i, &nums[n..]);
            let cl = &cache_left[n - i.count_ones() as usize];
            let absdiff = Solution::bsearch_min_absdiff(cl, sum_right);
            min_absdiff = min_absdiff.min(absdiff);
        }
        min_absdiff
    }

    fn subsum(bitset: u32, nums: &[i32]) -> i32 {
        nums.iter().enumerate().fold(
            0,
            |sum, (j, v)| if bitset & (1 << j) != 0 { sum + v } else { sum },
        )
    }

    fn bsearch_min_absdiff(cl: &[i32], sum_right: i32) -> i32 {
        match cl.binary_search(&(2 * sum_right)) {
            Ok(_) => 0,
            Err(j) => {
                if j == 0 {
                    (cl[j] - 2 * sum_right).abs()
                } else if j == cl.len() {
                    (cl[j - 1] - 2 * sum_right).abs()
                } else {
                    let absdiff_left = (cl[j - 1] - 2 * sum_right).abs();
                    let absdiff_right = (cl[j] - 2 * sum_right).abs();
                    absdiff_left.min(absdiff_right)
                }
            }
        }
    }
}
