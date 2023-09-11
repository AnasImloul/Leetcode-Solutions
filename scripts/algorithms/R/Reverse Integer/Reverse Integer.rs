// Runtime: 3 ms (Top 30.2%) | Memory: 2.07 MB (Top 48.8%)

impl Solution {
    pub fn reverse(x: i32) -> i32 {
        let mut x = x;
        let mut ret: i32 = 0;
        while x != 0 {
            let d: i32 = x % 10;
            x = x / 10;
            match ret.checked_mul(10).and_then(|val| val.checked_add(d)) {
                Some(val) => ret = val,
                None => return 0
            }
        }
        ret
    }
}