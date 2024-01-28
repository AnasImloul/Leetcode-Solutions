// Runtime: 37 ms (Top 84.62%) | Memory: 3.60 MB (Top 61.54%)

impl Solution {
    pub fn can_see_persons_count(heights: Vec<i32>) -> Vec<i32> {
        let n = heights.len();
        let mut stk: Vec<i32> = Vec::new();
        let mut ans: Vec<i32> = vec![0; n];
        for i in (0..n).rev() {
            let mut cnt = 0;
            while(!stk.is_empty() && heights[i] > stk[stk.len()-1]) {
                stk.pop();
                cnt += 1;
            }
            ans[i] = if stk.is_empty() {cnt} else {cnt+1};
            stk.push(heights[i]);
        }
        return ans;
    }
}
