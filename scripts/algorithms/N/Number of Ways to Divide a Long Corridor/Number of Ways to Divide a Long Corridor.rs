// Runtime: 11 ms (Top 90.52%) | Memory: 2.60 MB (Top 39.44%)

impl Solution {
    pub fn number_of_ways(corridor: String) -> i32 {
        const MOD: u64 = (1e9 + 7.) as _;

        let mut count = 1;
        let mut seats = 0;
        let mut j = None;

        for (i, c) in corridor.char_indices() {
            if c == 'S' {
                seats += 1;
                if seats == 2 {
                    j = Some(i);
                    seats = 0;
                } else if seats == 1 && j.is_some() {
                    count = (count * (i - j.unwrap()) as u64) % MOD;
                }
            }
        }

        if seats == 1 || j.is_none() {
            return 0;
        }

        count as _
    }
}
