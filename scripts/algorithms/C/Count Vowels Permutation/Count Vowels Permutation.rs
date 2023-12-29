// Runtime: 0 ms (Top 100.0%) | Memory: 2.30 MB (Top 28.0%)

impl Solution {
    pub fn count_vowel_permutation(n: i32) -> i32 {
        const MOD: i64 = 1e9 as i64 + 7;
        
        let mut a = 1;
        let mut e = 1;
        let mut i = 1;
        let mut o = 1;
        let mut u = 1;
        
        for _ in 1..n {
            let a_next = e;
            let e_next = (a + i) % MOD;
            let i_next = (a + e + o + u) % MOD;
            let o_next = (i + u) % MOD;
            let u_next = a;
            
            a = a_next;
            e = e_next;
            i = i_next;
            o = o_next;
            u = u_next;
        }
        
        ((a + e + i + o + u) % MOD) as i32
    }
}
