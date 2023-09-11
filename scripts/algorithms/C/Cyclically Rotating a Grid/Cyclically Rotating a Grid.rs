// Runtime: 6 ms (Top 100.0%) | Memory: 2.28 MB (Top 100.0%)

impl Solution {

  pub fn rotate_grid(grid: Vec<Vec<i32>>, k: i32) -> Vec<Vec<i32>> {

    let n = grid.len();

    let m = grid[0].len();



    let min = n.min(m) / 2;

    let k = k as usize;



    let mut result = grid.clone();

    for pi in 0..min {

      let mut temps = vec![];



      let x = pi;

      for y in pi..n-pi {

        temps.push((y,x));

      }



      let y = n-1-pi;

      for x in pi+1..m-pi {

        temps.push((y,x));

      }



      let x = m-1-pi;

      for y in (pi..n-1-pi).rev() {

        temps.push((y,x));

      }



      let y = pi;

      for x in (pi+1..m-1-pi).rev() {

        temps.push((y,x));

      }



      let len = temps.len();

      let ak = k % len;

      for i in 0..len {

        let (ci,cj) = temps[i];

        let (ti,tj) = temps[(i+ak) % len];

        result[ti][tj] = grid[ci][cj];

      }

    }



    result

  }

}