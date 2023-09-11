// Runtime: 15 ms (Top 25.0%) | Memory: 3.25 MB (Top 75.0%)

impl Solution {
    pub fn count_subarrays(nums: Vec<i32>, min_k: i32, max_k: i32) -> i64 {
        nums.split(|&x| x < min_k || x > max_k)
            .flat_map(|w| {
                w.iter().scan((0, 0, 0), move |(j, cnt_min, cnt_max), &wi| {
                    while *j < w.len() && (*cnt_min == 0 || *cnt_max == 0) {
                        if w[*j] == min_k {
                            *cnt_min += 1;
                        }
                        if w[*j] == max_k {
                            *cnt_max += 1;
                        }
                        *j += 1;
                    }
                    (*cnt_min > 0 && *cnt_max > 0).then(|| {
                        if wi == min_k {
                            *cnt_min -= 1;
                        }
                        if wi == max_k {
                            *cnt_max -= 1;
                        }
                        (w.len() - *j + 1) as i64
                    })
                })
            })
            .sum()
    }
}
