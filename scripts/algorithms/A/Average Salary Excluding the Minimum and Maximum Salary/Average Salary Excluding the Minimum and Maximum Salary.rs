// Runtime: 0 ms (Top 100.0%) | Memory: 2.05 MB (Top 68.4%)

impl Solution {
    pub fn average(salary: Vec<i32>) -> f64 {
        (salary.iter().fold(0, |acc, s| if s == salary.iter().min().unwrap() || s == salary.iter().max().unwrap() {acc} else {acc + s}) as f64) / (salary.len() - 2) as f64       
    }
}