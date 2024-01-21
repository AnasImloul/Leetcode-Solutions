// Runtime: 22 ms (Top 33.33%) | Memory: 2.20 MB (Top 33.33%)

const DICE_LEN: usize = 7;
const MOD: usize = 1_000_000_007;

pub fn gen_next_map() -> [u8; DICE_LEN] {
    [
        0b1111110, // 0 -> [1, 2, 3, 4, 5, 6]
        0b1111100, // 1 -> [2, 3, 4, 5, 6]
        0b0101010, // 2 -> [1, 3, 5]
        0b0110110, // 3 -> [1, 2, 4, 5]
        0b0101010, // 4 -> [1, 3, 5]
        0b1011110, // 5 -> [1, 2, 3, 4, 6]
        0b0100010, // 6 -> [1, 5]
    ]
}

impl Solution {
    pub fn distinct_sequences(n: i32) -> i32 {
        let n = n as usize - 1;

        let next_map = gen_next_map();

        let mut dp = [[usize::MIN; DICE_LEN]; DICE_LEN];
        for j in 1..DICE_LEN {
            dp[usize::MIN][j] = 1;
        }

        for _ in 0..n {
            let mut dp_next = [[usize::MIN; DICE_LEN]; DICE_LEN];

            for prev in 0..DICE_LEN {
                for i in 0..DICE_LEN {
                    let flags = next_map[i] & !(1 << prev);

                    for j in 0..DICE_LEN {
                        if (flags >> j) & 1 < 1 { continue; }
                        
                        dp_next[i][j] += dp[prev][i];
                    }
                }
            }

            for i in 0..DICE_LEN {
                for j in 0..DICE_LEN {
                    dp_next[i][j] %= MOD;
                }
            }
            dp = dp_next;
        }

        let ret = dp.into_iter()
            .map(|v| v.into_iter().sum::<usize>() % MOD)
            .sum::<usize>() % MOD;
        ret as i32
    }
}
