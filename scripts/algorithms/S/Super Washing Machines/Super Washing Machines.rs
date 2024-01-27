// Runtime: 0 ms (Top 100.0%) | Memory: 2.30 MB (Top 10.0%)

impl Solution {
    
    pub fn find_min_moves(machines: Vec<i32>) -> i32 {
        let total: i32 = machines.iter().sum();
        let machines_size = machines.len() as i32;
        
        if total % machines_size != 0 {
            return -1;
        }

        let avg = total / machines_size;
        let mut cnt = 0;
        let mut max_cnt = 0;

        for i in 0..machines_size {
            cnt += machines[i as usize] - avg;
            max_cnt = max_cnt.max((cnt.abs()).max(machines[i as usize] - avg));
        }

        max_cnt
    }

}
