// Runtime: 0 ms (Top 100.0%) | Memory: 2.20 MB (Top 50.0%)

impl Solution {
    pub fn num_sub(s: String) -> i32 {
        const MODULO: i64 = 10_i64.pow(9) + 7;
        let mut count: i64 = 0;
        let mut temp_count_1: i64 = 0;
        for (i, c) in s.chars().enumerate(){
            if c != '1'{
                count += (temp_count_1 * (temp_count_1+1)/2);
                temp_count_1 = 0;
                continue;
            }
            temp_count_1 += 1;
        }
        count += (temp_count_1 * (temp_count_1+1)/2);
        return (count % MODULO) as i32;
    }
}
