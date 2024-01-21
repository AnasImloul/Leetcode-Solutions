// Runtime: 0 ms (Top 100.0%) | Memory: 2.10 MB (Top 50.0%)

impl Solution {
    pub fn time_required_to_buy(mut tickets: Vec<i32>, k: i32) -> i32 {
        let mut sum = 0i32;
        let mut N = tickets[k as usize];
        for i in 0..tickets.len(){
            if N > tickets[i] {
                sum += tickets[i]
            } else {
                sum += N
            }
            if i == k as usize { N -=1 }
        }
        return sum;
    }
}
