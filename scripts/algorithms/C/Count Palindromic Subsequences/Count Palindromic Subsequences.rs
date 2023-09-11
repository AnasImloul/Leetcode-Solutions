// Runtime: 30 ms (Top 33.3%) | Memory: 22.77 MB (Top 66.6%)

const ALP_LEN: usize = 11;
type Char = u8;

const MOD: usize = 1_000_000_007;

pub fn to_freq_map(
    vec: &Vec<Char>,
) -> Vec<[[usize; ALP_LEN]; ALP_LEN]> {
    let mut dp = [usize::MIN; ALP_LEN];
    dp[ALP_LEN - 1] = 1;

    let mut count_map = [[usize::MIN; ALP_LEN]; ALP_LEN];
    count_map[ALP_LEN - 1][ALP_LEN - 1] = 1;

    let mut ret = vec![count_map];

    for &e in vec {
        for e_prev in 0..ALP_LEN {
            count_map[e as usize][e_prev] += dp[e_prev];
            count_map[e as usize][e_prev] %= MOD;
        }
        dp[e as usize] += 1;

        ret.push(count_map);
    }

    ret
}

impl Solution {
    pub fn count_palindromes(s: String) -> i32 {
        let mut vec = s.chars()
            .map(|c| c as Char - '0' as Char)
            .collect::<Vec<_>>();
        let n = vec.len();

        let pref_vec = to_freq_map(&vec);

        vec.reverse();
        let mut post_vec = to_freq_map(&vec);
        post_vec.reverse();

        let mut ret = usize::MIN;

        for (pref_map, post_map) in pref_vec.into_iter()
            .zip(post_vec.into_iter().skip(1)) {
            for c0 in 0..(ALP_LEN - 1) {
                for c1 in 0..(ALP_LEN - 1) {
                    let mut _ret = 1;
                    _ret *= pref_map[c0][c1];
                    _ret *= post_map[c0][c1];
                    _ret %= MOD;

                    ret += _ret;
                    ret %= MOD;
                }
            }
        }

        ret as i32
    }
}