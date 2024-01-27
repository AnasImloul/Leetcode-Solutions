// Runtime: 2 ms (Top 77.56%) | Memory: 2.20 MB (Top 71.54%)

impl Solution {
  pub fn num_special(M: Vec<Vec<i32>>) -> i32 {
    let (nx, ny) = (M[0].len(), M.len());
    let mut data_x = vec![0; nx];
    let mut data_y = vec![0; ny];

    for y in 0 .. ny {
      for x in 0 .. nx {
        if M[y][x] == 1 {
          data_x[x] += 1;
          data_y[y] += 1;
        }
      }
    }

    let mut res = 0;
    for y in 0 .. ny {
      for x in 0 .. nx {
        if M[y][x] == 1 && data_x[x] == 1 && data_y[y] == 1 {
          res += 1;
        }
      }
    } 

    return res;
  }
}
