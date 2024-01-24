// Runtime: 49 ms (Top 100.0%) | Memory: 6.50 MB (Top 100.0%)

impl Solution {
    pub fn full_bloom_flowers(flowers: Vec<Vec<i32>>, people: Vec<i32>) -> Vec<i32> {
        let get_time_and_sort = |i| { 
            let mut ret = flowers.iter().map(|f| f[i]).collect::<Vec<_>>();
            ret.sort();
            ret
        };
        let start = get_time_and_sort(0);
        let end = get_time_and_sort(1);

        people.into_iter().map(|time| {
            (start.partition_point(|&s| s <= time) - end.partition_point(|&e| e < time)) as i32
        }).collect()
    }
}
