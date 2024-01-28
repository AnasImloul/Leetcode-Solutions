// Runtime: 0 ms (Top 100.0%) | Memory: 2.20 MB (Top 79.31%)

impl Solution {
    pub fn flood_fill(mut image: Vec<Vec<i32>>, sr: i32, sc: i32, new_color: i32) -> Vec<Vec<i32>> {
        let old_color = image[sr as usize][sc as usize];
        if old_color == new_color {
            return image;
        }
        let mut stack = vec![(sr as usize, sc as usize)];
        while let Some((i, j)) = stack.pop() {
            if image[i][j] != old_color {
                continue;
            }
            image[i][j] = new_color;
            if i > 0 {
                stack.push((i - 1, j));
            }
            if i < image.len() - 1 {
                stack.push((i + 1, j))
            }
            if j > 0 {
                stack.push((i, j - 1));
            }
            if j < image[0].len() - 1 {
                stack.push((i, j + 1));
            }   
        }
        image
    }
}
