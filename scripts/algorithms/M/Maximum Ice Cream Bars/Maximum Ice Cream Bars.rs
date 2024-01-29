// Runtime: 11 ms (Top 100.0%) | Memory: 4.20 MB (Top 6.25%)

impl Solution {
    pub fn max_ice_cream(costs: Vec<i32>, coins: i32) -> i32 {
        let mut bars  = [0_u32; 100_001];
        let mut coins = coins;
        let mut price = 1;
        let mut count = 0;

        costs.into_iter().for_each(|c| bars[c as usize] += 1);

        while coins >= price && price <= 100_000 {
            while bars[price as usize] > 0 && coins >= price {
                bars[price as usize] -= 1;
                coins -= price;
                count += 1;
            }
            price += 1;
        }
        count
    }
}
