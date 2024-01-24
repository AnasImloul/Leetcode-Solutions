// Runtime: 0 ms (Top 100.0%) | Memory: 2.00 MB (Top 94.74%)

impl Solution {
    pub fn num_tilings(n: i32) -> i32 {
        // DP by considering filling the last column of space
        // T(n) = T(n - 1)      | end with one vertical domino
        //      + T(n - 2)      | end with two horizontal domino
        //      + T_up(n - 1)   | end with trimino filling the former lower grid
        //      + T_down(n - 1) | end with trimino filling the former upper grid//
        // T_up(n): having an unfilled lower grid, therefore it can be formed by
        // T_up(n) = T(n - 2)      | Fully filled followed with a trimino filling lower grid
        //         + T_down(n - 1) | T_down(n - 1) with an upper horizontal domino
        // T_down(n): equivalent as above
        // T_down(n) = T(n - 2)
        //           + T_up(n - 1)

        // To sum up:
        // T(n) = T(n-1) + T(n-2) + T_up(n-1) + T_down(n-1)
        // T_up(n-1) = T_down(n-2) + T(n-3)
        // T_down(n-1) = T_up(n-2) + T(n-3)
        // --> T(n) = T(n-1) + T(n-2) + T_down(n-2) + T(n-3) + T_up(n-2) + T(n-3)
        // --> T(n) = T(n-1) + T(n-3) + [T(n-2) + T(n-3) + T_up(n-2) + T_down(n-2)]
        // --> T(n) = 2 * T(n-1) + T(n-3)

        // Since every state change only concerns the previous three values
        // Space can be reduced to O(1) in three variables

        // Base case by reverse calculation:
        // Initially, T(0) = 0, T(1) = 1, T(2) = 2, T(3) = 5 ...
        // Thus, T(2) = 2 * T(1) + T(-1) --> T(-1) = 0
        //       T(1) = 2 * T(0) + T(-2) --> T(-2) = -1

        const MOD: i32 = 1_000_000_007;
        // T(n-3), T(n-2), T(n-1) respectively
        let (mut x, mut y, mut z) = (-1, 0, 1);
        for _ in 1..=n {
            let cur = (2 * z % MOD + x) % MOD; // mod everytime to prevent overflow
            x = y;
            y = z;
            z = cur;
        }
        z
    }
}
