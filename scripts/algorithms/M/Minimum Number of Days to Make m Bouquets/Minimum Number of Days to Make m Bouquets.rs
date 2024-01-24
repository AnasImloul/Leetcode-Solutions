// Runtime: 14 ms (Top 100.0%) | Memory: 4.10 MB (Top 75.0%)

impl Solution {
    pub fn min_days(bloom_day: Vec<i32>, m: i32, k: i32) -> i32 {
        let val = m as i64 * k as i64;
        let len = bloom_day.len() as i64;

        if val > len {
            return -1;
        }
        
        let (mut start, mut end) = Solution::min_max(&bloom_day);
        

        while start <= end {
            let mid  = (start + end) / 2;
            if Solution::is_possible(&bloom_day, mid, m ,k) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        
        return start;
    }

    fn min_max(bloom_day: &Vec<i32>) -> (i32, i32) {
        let (mut min, mut max) = (i32::MAX, 0);

        for num in bloom_day {
            if *num < min {
                min = *num;
            }

            if *num > max {
                max = *num;
            }
        }


        return (min, max);
    }

    fn is_possible(bloom_day: &Vec<i32>, day: i32, m: i32, k: i32) -> bool {
        let (mut count, mut no_of_bouquets) = (0, 0);
        for num in bloom_day {
            if *num <= day {
                count += 1;
            } else {
                no_of_bouquets += (count / k) as i32;
                count = 0;
            }
        }

        no_of_bouquets += (count / k) as i32;

        if no_of_bouquets >= m {
            return true;
        }

        return false;
    }
}
