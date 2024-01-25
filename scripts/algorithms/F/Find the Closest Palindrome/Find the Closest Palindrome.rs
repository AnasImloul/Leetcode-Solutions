// Runtime: 1 ms (Top 100.0%) | Memory: 2.20 MB (Top 40.0%)

// Mfw I can't do a q. in > 12 lines:

impl Solution {
    pub fn nearest_palindromic(s: String) -> String {
        let num = s.parse::<i64>().unwrap();
        let len = s.len();

        let half = s[0..(len + 1) / 2].parse::<i64>().unwrap();

        let mut candidates = vec![
            10i64.pow(len as u32) + 1,
            10i64.pow(len as u32 - 1) - 1,
        ];

        for &i in &[half - 1, half, half + 1] {
            let mut cand_str = i.to_string();
            let rev = cand_str.chars().rev().collect::<String>();

            if len % 2 != 0 { cand_str.pop(); }

            cand_str.push_str(&rev);
            candidates.push(cand_str.parse().unwrap());
        }

        candidates.into_iter()
            .filter(|&c| c != num)
            .min_by_key(|&c| ((c - num).abs(), c))
            .unwrap()
            .to_string()
    }
}
