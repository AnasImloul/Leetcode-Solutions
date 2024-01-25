// Runtime: 0 ms (Top 100.0%) | Memory: 2.70 MB (Top 95.0%)

impl Solution {
    pub fn min_steps(s: String, t: String) -> i32 {
        let mut counter1: [i32;26] = [0;26];
        let mut counter2: [i32;26] = [0;26];
        for c in s.as_bytes() {
            counter1[(*c as usize)-97]+=1;
        }
        for c in t.as_bytes() {
            counter2[(*c as usize)-97]+=1;
        }

        (0..26).map(|i| (counter1[i]-counter2[i]).abs()).sum::<i32>()

    }
}
