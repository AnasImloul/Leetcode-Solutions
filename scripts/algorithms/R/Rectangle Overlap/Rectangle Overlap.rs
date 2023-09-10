// Runtime: 0 ms (Top 100.0%) | Memory: 2.10 MB (Top 28.5%)

const X1: usize = 0;
const Y1: usize = 1;
const X2: usize = 2;
const Y2: usize = 3;

impl Solution {
    pub fn is_rectangle_overlap(rec1: Vec<i32>, rec2: Vec<i32>) 
        -> bool 
    {
        rec1[X1] < rec2[X2] && rec1[X2] > rec2[X1] &&
        rec1[Y1] < rec2[Y2] && rec1[Y2] > rec2[Y1]
    }
}