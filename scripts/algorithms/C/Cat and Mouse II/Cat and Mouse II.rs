// Runtime: 371 ms (Top 100.0%) | Memory: 3.50 MB (Top 100.0%)

impl Solution {
    pub fn can_mouse_win(grid: Vec<String>, cat_jump: i32, mouse_jump: i32) -> bool {
        fn get_jumps(grid: &Vec<String>, p: i32, f: i32, max: i32) -> Vec<i32> {
            let dirs = [0, 1, 0, -1, 0];
            let mut res = vec![p];
            for d in 0..4 {
                for jump in 1..=max {
                    let i = p / 8 + dirs[d] * jump;
                    let j = p % 8 + dirs[d + 1] * jump;
                    if i < 0
                        || j < 0
                        || i as usize >= grid.len()
                        || j as usize >= grid[i as usize].len()
                        || grid[i as usize].chars().nth(j as usize).unwrap() == '#'
                    {
                        break;
                    }
                    res.push(i * 8 + j);
                }
            }
            res.sort_by(|&a, &b| {
                let v1 = (f / 8 - a / 8).abs() + (f % 8 - a % 8).abs();
                let v2 = (f / 8 - b / 8).abs() + (f % 8 - b % 8).abs();
                v1.cmp(&v2)
            });
            res
        }

        #[allow(clippy::too_many_arguments)]
        fn dfs(
            grid: &Vec<String>,
            turn: i32,
            c: i32,
            m: i32,
            f: i32,
            cat_jump: i32,
            mouse_jump: i32,
            dp: &mut Vec<Vec<Vec<i32>>>,
        ) -> bool {
            if turn >= 0 && (m == f || dp[turn as usize][m as usize][c as usize] == 1) {
                return true;
            }
            if turn < 0 || c == m || c == f || dp[turn as usize][m as usize][c as usize] == -1 {
                return false;
            }
            let cat_jumps = get_jumps(grid, c, f, cat_jump);
            for new_m in get_jumps(grid, m, f, mouse_jump) {
                let mut mouse_won = true;
                for &jmp in cat_jumps.iter() {
                    mouse_won &= dfs(grid, turn - 1, jmp, new_m, f, cat_jump, mouse_jump, dp);
                }
                if mouse_won {
                    dp[turn as usize][m as usize][c as usize] = 1;
                    return true;
                }
            }
            dp[turn as usize][m as usize][c as usize] = -1;
            false
        }

        let mut dp = vec![vec![vec![0; 64]; 64]; 64];
        let (mut c, mut m, mut f, rows, cols) = (0_i32, 0_i32, 0_i32, grid.len() as i32, grid[0].len() as i32);
        let turns = rows * cols - 1;
        for i in 0..rows {
            for j in 0..cols {
                m = if grid[i as usize].chars().nth(j as usize).unwrap() == 'M' {
                    i * 8 + j
                } else {
                    m
                };
                c = if grid[i as usize].chars().nth(j as usize).unwrap() == 'C' {
                    i * 8 + j
                } else {
                    c
                };
                f = if grid[i as usize].chars().nth(j as usize).unwrap() == 'F' {
                    i * 8 + j
                } else {
                    f
                };
            }
        }
        dfs(&grid, turns, c, m, f, cat_jump, mouse_jump, &mut dp)
    }
}
