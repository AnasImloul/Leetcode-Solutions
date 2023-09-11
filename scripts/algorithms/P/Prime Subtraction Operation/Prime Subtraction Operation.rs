// Runtime: 0 ms (Top 100.0%) | Memory: 2.11 MB (Top 20.0%)

impl Solution {
    pub fn prime_sub_operation(nums: Vec<i32>) -> bool {
        use std::cmp::Ordering;
        fn lower_bound_by<T, F>(arr: &[T], f: F) -> Result<usize, usize>
        where
            T: Ord,
            F: Fn(&T) -> Ordering,
        {
            arr.iter().position(|y| f(y) != Ordering::Less).ok_or(arr.len())
        }

        fn lower_bound<T: Ord>(arr: &[T], x: &T) -> Result<usize, usize> {
            lower_bound_by(arr, |y| y.cmp(x))
        }

        fn get_primes() -> Vec<i32> {
            let mut ps = vec![2];
            let mut sieve = vec![false; 1001];
            for i in 3..32 {
                if !sieve[i] {
                    for j in (i * i..=1000).step_by(i) {
                        sieve[j] = true;
                    }
                }
            }
            for i in (3..=1000).step_by(2) {
                if !sieve[i as usize] {
                    ps.push(i);
                }
            }
            ps
        }

        let mut nums = nums;
        let ps = get_primes();
        for i in 0..nums.len() {
            let it = lower_bound(&ps, &(nums[i] - if i > 0 { nums[i - 1] } else { 0 }));
            let it = it.unwrap_or(ps.len());
            if it > 0 {
                nums[i] -= ps[it - 1];
            }
            if i > 0 && nums[i] <= nums[i - 1] {
                return false;
            }
        }

        true
    }
}