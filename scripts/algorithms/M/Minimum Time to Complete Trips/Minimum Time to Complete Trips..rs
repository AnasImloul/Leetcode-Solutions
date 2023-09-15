// Runtime: 50 ms (Top 100.0%) | Memory: 3.41 MB (Top 100.0%)

impl Solution {
    pub fn minimum_time(time: Vec<i32>, total_trips: i32) -> i64 {
        let total_trips = total_trips as i64;
        let mut max_time = time.iter().min().unwrap().clone() as i64 * total_trips;
        let mut min_time = 1 as i64;

        while min_time < max_time {
            let mid_time = (min_time + max_time) / 2;
            let trips = time.iter().fold(0, |subtotal, trip_time| {
                subtotal + mid_time / trip_time.clone() as i64
            });

            if trips < total_trips {
                min_time = mid_time + 1;
            } else {
                max_time = mid_time;
            }
        }

        min_time
    }
}