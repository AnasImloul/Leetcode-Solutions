// Runtime: 7 ms (Top 95.56%) | Memory: 2.80 MB (Top 86.67%)

impl Solution {
    pub fn lemonade_change(bills: Vec<i32>) -> bool {
        bills.into_iter().try_fold([0,0],|[a,b],x|
            match x {
                5  => Some([a+1, b]),
                10 if a > 0 => Some([a-1,b+1]),
                20 if a > 0 && b > 0  => Some([a-1, b-1]),
                20 if a > 2 && b == 0 => Some([a-3, b]),
                _ => None,
                }
        ).is_some()
    }
}
