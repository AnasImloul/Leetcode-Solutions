// Runtime: 0 ms (Top 100.0%) | Memory: 2.20 MB (Top 41.59%)

use std::collections::HashMap;
use std::cmp::max;

fn bad_character_table(pattern: &Vec<char>) -> HashMap<char, usize> {
    let mut table = HashMap::new();
    let m = pattern.len();

    for i in 0..m-1 {
        table.insert(pattern[i], m-1-i);
    }

    table
}

fn suffix_length_table(pattern: &Vec<char>) -> Vec<usize> {
    let m = pattern.len();
    let (mut f, mut g) = (0usize, m-1);
    let mut table = vec![m; m];

    for i in (0..m-1).rev() {
        if i > g && table[i+m-1-f] < i-g {
            table[i] = table[i+m-1-f];
            continue;
        }

        if i < g { g = i; }
        f = i;

        table[i] = (0..=i).rev()
                          .take_while(|&j| pattern[j] == pattern[m-1-i+j])
                          .count();
    }

    table
}

fn good_suffix_table(pattern: &Vec<char>) -> Vec<usize> {
    let m = pattern.len();
    let mut table = vec![m; m];
    let suffix = suffix_length_table(pattern);

    let mut last_prefix_position = m;
    for i in (1..m).rev() {
        if suffix[m-1-i] == m - i {
            last_prefix_position = i;
        }
        table[m-i] = last_prefix_position - i + m; 
    }

    (0..m-1).for_each(|i| table[suffix[i]] = m - 1 - i + suffix[i]);

    table
}

fn boyer_moore(text: Vec<char>, pattern: Vec<char>) -> i32 {
    let m = pattern.len();
    let end = text.len();

    let char_table = bad_character_table(&pattern);
    let offset_table = good_suffix_table(&pattern);

    let mut i = m - 1;
    while i < end {
        let matches = (0..m).rev()
                            .take_while(|&j| pattern[j] == text[i-(m-1-j)])
                            .count();

        i -= matches;

        if matches == m {
            return i as i32 + 1;
        }

        i += max(
                 offset_table[matches],
                 *char_table.get(&text[i]).unwrap_or(&m)
                );
    }

    -1
}

impl Solution {
    pub fn str_str(haystack: String, needle: String) -> i32 {
        if needle.is_empty() {
            0
        } else {
            boyer_moore(haystack.chars().collect(), needle.chars().collect())
        }
    }
}
