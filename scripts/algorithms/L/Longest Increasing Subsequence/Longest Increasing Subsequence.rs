// Runtime: 1 ms (Top 89.14%) | Memory: 2.00 MB (Top 98.48%)

impl Solution {
    pub fn length_of_lis(nums: Vec<i32>) -> i32 {
        let mut v: Vec<i32> = vec![*nums.first().unwrap()];
        for n in nums.iter() {
            if n > v.last().unwrap() {
                v.push(*n);
            } else {
                let pos = v.binary_search(n);
                if let Err(pos) = pos {
                    if v[pos] > *n {
                        v[pos] = *n;
                    }
                }
            }
        }
        v.len() as i32
    }
}
