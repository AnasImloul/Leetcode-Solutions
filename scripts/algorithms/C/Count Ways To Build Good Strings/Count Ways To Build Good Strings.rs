// Runtime: 0 ms (Top 100.0%) | Memory: 2.60 MB (Top 66.67%)

use std::collections::VecDeque;
impl Solution {
    pub fn count_good_strings(low: i32, high: i32, zero: i32, one: i32) -> i32 {
        const MOD_VAL: usize = 1000000007;
        let smaller = one.min(zero);
        let bigger = one.max(zero);
        let mut circular_buf = VecDeque::<usize>::with_capacity((bigger + 1) as usize);
        
        // good_strings(0) should be 1, because technically
        // "" is a string made up of some 1s and some 0s
        // but more importantly, 
        // dp[i - smaller] when i = smaller will be dp[0]
        // similarly dp[i - bigger] when i = bigger will be dp[0]
        // and the answer for i = {smaller, bigger} must be 1, not 0.
        circular_buf.push_back(1);


        // For the rest of them up until min(zero, one), there's definitely no way to make that string.
        for _ in 1..smaller {
            circular_buf.push_back(0);
        }

        let mut counter: usize = 0;

        // In this range, all the multiples of min(zero, one) can be made, and the rest can't.
        
        for i in smaller..bigger {
            let ans = circular_buf[(i - smaller) as usize];
            circular_buf.push_back(ans);
            if i >= low {
                counter += ans;
            }
        }

        // We didn't pop from the queue until we had max(zero, one) amt of elements, 
        // because atleast that many elements must be present before proceeding with the general case.
        for i in bigger..=high {
            // the indexing will be [bigger - {zero, one}]
            // because at any given time, the i_th index is really `bigger`
            // we insert at the length of the queue, and length is always `bigger`, as we keep popping the last element as soon as length becomes `bigger` + 1.
            let ans = (circular_buf[(bigger - zero) as usize]
                + circular_buf[(bigger - one) as usize])
                % MOD_VAL;
            circular_buf.push_back(ans);
            circular_buf.pop_front();

            if i >= low {
                counter = (counter + ans) % MOD_VAL;
            }
        }

        counter as i32
    }
}
