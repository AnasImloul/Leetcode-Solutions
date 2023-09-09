// Runtime: 2 ms (Top 55.1%) | Memory: 2.12 MB (Top 20.4%)

impl Solution {
    pub fn find_delayed_arrival_time(arrival_time: i32, delayed_time: i32) -> i32 {
        (arrival_time + delayed_time) % 24
    }
}