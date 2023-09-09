// Runtime: 8 ms (Top 60.0%) | Memory: 2.55 MB (Top 20.0%)

impl Solution {
    pub fn find_substring_in_wrapround_string(s: String) -> i32 {
        let mut res: std::collections::HashMap<u8,i32> = s.bytes().map(|b| (b,1)).collect();
        let mut l = 1;
        for (i, j) in s.bytes().zip(s.bytes().skip(1)) {
            l = if i == j -1 || i == j + 25 {l + 1} else {1};
            res.insert(j,res[&j].max(l));
        }
        return res.values().sum()
    }
}