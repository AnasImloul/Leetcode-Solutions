// Runtime: 7 ms (Top 79.7%) | Memory: 2.22 MB (Top 33.8%)

impl Solution {
    pub fn find_longest_chain(mut pairs: Vec<Vec<i32>>) -> i32 {
        // sort by second element of the pair
        pairs.sort_by(|a, b| a[1].cmp(&b[1]));

        // count the number of pairs that dont overlap
        let mut count = 1;
        let mut prev = pairs[0][1];
        for i in 1..pairs.len() {
            if pairs[i][0] > prev {
                count += 1;
                prev = pairs[i][1];
            }
        }

        count
    }
}