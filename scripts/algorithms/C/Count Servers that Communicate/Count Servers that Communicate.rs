// Runtime: 0 ms (Top 100.0%) | Memory: 2.60 MB (Top 50.0%)

impl Solution {
    pub fn count_servers(grid: Vec<Vec<i32>>) -> i32 {
        let n :usize= grid.len();
        let m :usize = grid[0].len();
        let mut row: Vec<i32> = vec![0;n];
        let mut col: Vec<i32> = vec![0;m];
        
        let mut res: i32 = 0;
        
        //count number of servers in each row and column
        for i in 0..n{
            for j in 0..m{
                if grid[i][j]==1{
                    row[i]+=1;
                    col[j]+=1;
                }
            }
        }
        
        //count number of servers not alone in either row or column
        for i in 0..n{
            for j in 0..m{
                if grid[i][j]==1 && (row[i]>1||col[j]>1){
                    res+=1;
                }
            }
        }
        return res;
    }
}
