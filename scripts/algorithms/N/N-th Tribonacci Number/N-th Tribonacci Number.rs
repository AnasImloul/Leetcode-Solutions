// Runtime: 0 ms (Top 100.0%) | Memory: 2.20 MB (Top 10.53%)

impl Solution {
    /*
        | T(n+2) T(n+1) T(n)   |   | 1 1 0 |   | T(n+3) T(n+2) T(n+1) |
        | T(n+1) T(n)   T(n-1) | * | 1 0 1 | = | T(n+2) T(n+1) T(n)   |
        | T(n)   T(n-1) T(n-2) |   | 1 0 0 |   | T(n+1) T(n)   T(n-1) |
    */
    pub fn tribonacci(n: i32) -> i32 {
        match n {
            0 => 0,
            1 | 2 => 1,
            n => {
                fn mul(m: &[[i32; 3]; 3], e: &[[i32; 3]; 3]) -> [[i32; 3]; 3] {
                    let x = |row:usize, col:usize| m[row].iter().zip(e.iter().map(|r| r[col])).map(|(a,b)| a*b).sum();
                    [[x(0,0), x(0,1), x(0,2)], [x(1,0), x(1,1), x(1,2)], [x(2,0), x(2,1), x(2,2)]]
                }
                let mut m = [[2, 1, 1], [1, 1, 0], [1, 0, 0]]; // initial matrix
                let mut e = [[1, 1, 0], [1, 0, 1], [1, 0, 0]]; // linear operator
                let mut n = n - 3;
                while n > 0 {
                    if n & 1 > 0 {
                        m = mul(&m, &e);
                    }
                    e = mul(&e, &e);
                    n >>= 1;
                }
                m[0][0]
            }
        }
    }
}
