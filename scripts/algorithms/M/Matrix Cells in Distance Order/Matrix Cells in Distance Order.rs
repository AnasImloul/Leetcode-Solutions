// Runtime: 13 ms (Top 50.0%) | Memory: 2.70 MB (Top 100.0%)

struct Cell {
  r:i32,
  c:i32,
  d:i32,
}

impl Solution {

  pub fn all_cells_dist_order(rows: i32, cols: i32, r_center: i32, c_center: i32) -> Vec<Vec<i32>> {
    let mut ret  = Vec::new();
    let mut cells  = Vec::new();
    for r in 0..rows {
      for c in 0..cols {
        let dist = (r_center - r).abs() + (c_center - c).abs();
        let cell = Cell {
          r:r,
          c:c,
          d:dist
        };
        cells.push(cell);
      }
    }
    cells.sort_by(|a,b| a.d.cmp(&b.d));
    for cl in cells {
      ret.push(vec![cl.r,cl.c]);
    }
    ret
  }
}
