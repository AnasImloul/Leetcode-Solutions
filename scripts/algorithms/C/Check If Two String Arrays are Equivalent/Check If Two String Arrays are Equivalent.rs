// Runtime: 0 ms (Top 100.0%) | Memory: 2.30 MB (Top 17.91%)

impl Solution {
    pub fn array_strings_are_equal(word1: Vec<String>, word2: Vec<String>) -> bool {
        word1.join("") == word2.join("")
    }
}
