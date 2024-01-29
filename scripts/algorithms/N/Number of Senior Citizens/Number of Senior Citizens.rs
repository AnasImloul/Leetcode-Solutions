// Runtime: 1 ms (Top 76.47%) | Memory: 2.10 MB (Top 85.29%)

impl Solution {
    pub fn count_seniors(details: Vec<String>) -> i32 {
        let mut count = 0;
        for d in details.iter(){
            let age = &d[11..13].parse::<i32>().unwrap();
            if *age > 60{
                count += 1;
            }
        }
        count
    }
}
