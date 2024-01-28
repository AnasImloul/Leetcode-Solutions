// Runtime: 2 ms (Top 83.33%) | Memory: 2.00 MB (Top 100.0%)

impl Solution {
    pub fn largest_merge(word1: String, word2: String) -> String {
        let mut slice1 = word1.as_bytes();
        let mut slice2 = word2.as_bytes();
        let mut ans = Vec::with_capacity(word1.len() + word2.len());
        while !slice1.is_empty() && !slice2.is_empty() {
            if slice1 > slice2 {
                ans.push(slice1[0]);
                slice1 = &slice1[1..];
            } else {
                ans.push(slice2[0]);
                slice2 = &slice2[1..];
            }
        }
        ans.extend(slice1);
        ans.extend(slice2);
        unsafe {String::from_utf8_unchecked(ans)}
    }
}
