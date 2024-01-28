// Runtime: 105 ms (Top 66.67%) | Memory: 72.80 MB (Top 16.67%)

/**
 * @param {number[]} obstacles
 * @return {number}
 */
// var solve = function(obstacles, lane, pos, dp) {
//     if (pos === obstacles.length - 1) {
//         return 0;
//     }
//     // Obstacle on next straight position
//     if (dp[lane][pos] !== -1) {
//         return dp[lane][pos];
//     }
//     if (obstacles[pos + 1] !== lane) {
//         return solve(obstacles, lane, pos + 1, dp);
//     } else {
//         let ans = Number.MAX_SAFE_INTEGER;
//         for (let i = 1; i <= 3; i++) {
//             if (i !== lane && obstacles[pos] !== i) {
//                 ans = Math.min(ans, 1 + solve(obstacles, i, pos + 1, dp)); // Updated pos here
//             }
//         }
//         dp[lane][pos] = ans;
//         return ans;
//     }
// };

// var minSideJumps = function(obstacles) {
//     let dp = Array.from({ length: 4 }, () => Array(obstacles.length).fill(-1));
//     return solve(obstacles, 2, 0, dp);
// };

// var minSideJumps = function(obstacles) {
//     let n = obstacles.length;
//     let dp = Array.from({ length: 4 }, () => Array(n).fill(Number.MAX_SAFE_INTEGER));
    
//     // Initialize the last column of dp to 0
//     dp[0][n - 1] = 0;
//     dp[1][n - 1] = 0;
//     dp[2][n - 1] = 0;
//     dp[3][n - 1] = 0;

//     for (let pos = n - 2; pos >= 0; pos--) {
//         for (let lane = 1; lane <= 3; lane++) {
//             if (obstacles[pos + 1] !== lane) {
//                 dp[lane][pos] = dp[lane][pos + 1];
//             } else {
//                 let ans = Number.MAX_SAFE_INTEGER;
//                 for (let i = 1; i <= 3; i++) {
//                     if (i !== lane && obstacles[pos] !== i) {
//                         ans = Math.min(ans, 1 + dp[i][pos + 1]);
//                     }
//                 }
//                 dp[lane][pos] = ans;
//             }
//         }
//     }
    
//     // Fix the return statement
//     return Math.min(dp[2][0], Math.min(1 + dp[1][0], 1 + dp[3][0]));
// };

var minSideJumps = function(obstacles) { 
let n = obstacles.length;
    let curr = Array(4).fill(Number.MAX_SAFE_INTEGER)
    let next = Array(4).fill(0)

    for (let pos = n - 2; pos >= 0; pos--) {
        for (let lane = 1; lane <= 3; lane++) {
            if (obstacles[pos + 1] !== lane) {
                curr[lane] = next[lane]
            } else {
                let ans = Number.MAX_SAFE_INTEGER;
                for (let i = 1; i <= 3; i++) {
                    if (i !== lane && obstacles[pos] !== i) {
                        ans = Math.min(ans, 1 + next[i]);
                    }
                }
                curr[lane] = ans;
                next = curr
            }
        }
    }
    return Math.min(next[2], Math.min(1 + next[1], 1 + next[0]));
}

