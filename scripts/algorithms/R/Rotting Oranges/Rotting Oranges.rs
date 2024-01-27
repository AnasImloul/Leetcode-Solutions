// Runtime: 0 ms (Top 100.0%) | Memory: 2.10 MB (Top 47.46%)

use std::collections::{HashSet, VecDeque};

const DIRECTIONS: [(isize, isize); 4] = [(1, 0), (0, 1), (-1, 0), (0, -1)];
impl Solution {
    pub fn oranges_rotting(grid: Vec<Vec<i32>>) -> i32 {
        let mut queue = VecDeque::new();
        let mut seen = HashSet::new();
        let mut minutes = 0;

        // fill the queue with all rotten oranges
        for i in 0..grid.len() {
            for j in 0..grid[0].len() {
                if grid[i][j] == 2 {
                    queue.push_back((i as isize, j as isize, 0));
                    seen.insert((i, j));
                }
            }
        }

        // perform bfs and spread rotting orange
        while let Some((i, j, time)) = queue.pop_front() {

            for &(di, dj) in &DIRECTIONS {
                let next_i = i + di;
                let next_j = j + dj;

                if next_i >= 0 && next_j >= 0 && next_i < grid.len() as isize && next_j < grid[0].len() as isize && !seen.contains(&(next_i as usize, next_j as usize)) && grid[next_i as usize][next_j as usize] == 1 {
                    queue.push_back((next_i, next_j, time + 1));
                    seen.insert((next_i as usize, next_j as usize));
                    minutes = time + 1;
                }
            }
        }

        // make sure all oranges are rotted; if any aren't then its impossible to rot all oranges
        for i in 0..grid.len() {
            for j in 0..grid[0].len() {
                if grid[i][j] == 1 && !seen.contains(&(i, j)) {
                    return -1;
                }
            }
        }

        minutes
    }

}
