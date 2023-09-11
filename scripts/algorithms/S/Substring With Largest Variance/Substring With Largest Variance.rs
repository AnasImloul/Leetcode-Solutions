// Runtime: 67 ms (Top 63.6%) | Memory: 2.05 MB (Top 100.0%)

impl Solution {
    pub fn largest_variance(s: String) -> i32 {
        let au = 'a' as u8;
        let s = s.into_bytes();
        let counter = s.iter().fold(vec![0; 26], |mut vec, ch| {
            vec[(ch - au) as usize] += 1;
            vec
        });

        let mut g_max = 0;

        for i in 0..26 {
            for j in 0..26 {
                if i == j || counter[i] == 0 || counter[j] == 0 {
                    continue;
                }

                let (maj, min) = (i as u8 + au, j as u8 + au);
                let (mut maj_c, mut min_c) = (0, 0);
                let mut min_r = counter[j];

                s.iter().for_each(|c| {
                    match c {
                        x if *x == maj => { maj_c += 1; }
                        y if *y == min => { min_c += 1; min_r -= 1; }
                        _ => (),
                    }

                    if min_c > 0 {
                        g_max = g_max.max(maj_c - min_c);
                    }

                    if maj_c < min_c && min_r > 0 {
                        maj_c = 0;
                        min_c = 0;
                    }
                });
            }
        }

        g_max
    }
}