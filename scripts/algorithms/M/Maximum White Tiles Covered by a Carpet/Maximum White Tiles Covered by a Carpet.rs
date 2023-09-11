// Runtime: 47 ms (Top 100.0%) | Memory: 6.62 MB (Top 100.0%)

impl Solution {
    pub fn maximum_white_tiles(mut tiles: Vec<Vec<i32>>, carpet_len: i32) -> i32 {
        let n = tiles.len();
        tiles.sort_by(|a,b| a[0].cmp(&b[0]));

        let mut stack = vec![tiles[0][1] - tiles[0][0] + 1];
        for i in 1..n {
            stack.push(tiles[i][0] - tiles[i-1][1] - 1);
            stack.push(tiles[i][1] - tiles[i][0] + 1);
        }
        
        let n = stack.len();
        let mut memo = vec![(0,0,false);n+1];

        for i in 0..n {
            memo[i+1].0 = memo[i].0;
            memo[i+1].1 = memo[i].1;
            memo[i+1].0 += stack[i];
            if i % 2 == 0 {
                memo[i+1].1 += stack[i];
                memo[i+1].2 = true;
            } 
        }

        let mut max = 0;
        let mut ri = 0;
        for li in 0..n {
            while ri < n && memo[ri].0 - memo[li].0 <= carpet_len {
                ri += 1;
            }

            let sum = memo[ri].0 - memo[li].0;
            let score = memo[ri].1 - memo[li].1;
            if memo[ri].2 {
                if sum < carpet_len {
                    max = std::cmp::max(max, score);
                } else {
                    let over = sum - carpet_len;
                    let actual_score = score - over;
                    max = std::cmp::max(max, actual_score);
                }
                } else {
                max = std::cmp::max(max, score);
            }
        }

        max.min(carpet_len)
    }
}