// Runtime: 0 ms (Top 100.0%) | Memory: 2.30 MB (Top 75.0%)

impl Solution {
    pub fn largest1_bordered_square(grid: Vec<Vec<i32>>) -> i32 {
        let mut max_len:i32 = 0;
        for i in 0..grid.len() {
            let mut tmp_max: i32 = 0;
            for j in 0..grid[0].len() {
                if grid[i][j] == 1 {
                    tmp_max += 1;
                    if tmp_max > max_len {
                        
                        if tmp_max == 1 {
                            max_len = 1;
                        } else {
                            for k in ((j as i32)-tmp_max+1) as usize..j {
                                if Solution::check_valid_square(&grid, i, k,j-k +1) {
                                    // println!("in line {}, the max is {}, col is {}", i, tmp_max,(tmp_max-k as i32));
                                    if (j-k+1)as i32 > max_len {
                                        max_len = (j-k+1)as i32;
                                    }
                                    
                                }
                            }
                          
                        }
                    }
                } else {
                    tmp_max = 0;
                }
            }
        }
        max_len * max_len
    }
    pub fn check_valid_square(matrix: &Vec<Vec<i32>>, r: usize, c: usize, len:usize) -> bool {
        if r+len-1 >= matrix.len() {
            return false
        }
        for j in c..(c+len) {
            if  matrix[r][j] == 0 ||matrix[r+len-1][j] == 0 {
                return false
            }
        }
        
        for i in r..(r+len) {
            if  matrix[i][c+len-1] == 0 || matrix[i][c] == 0{
                return false
            }
        }
        true
    }
}
