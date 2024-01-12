// Runtime: 1 ms (Top 85.0%) | Memory: 2.30 MB (Top 10.0%)

impl Solution {
    pub fn final_prices(prices: Vec<i32>) -> Vec<i32> {
        let mut res = Vec::with_capacity(prices.len());
        'main: for (i, &ai) in prices.iter().enumerate() {
            for &aj in prices.iter().skip(i + 1) {
                if aj <= ai {
                    res.push(ai - aj);
                    continue 'main;
                }
            }
            res.push(ai);
        }
        res
    }
}
