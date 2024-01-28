// Runtime: 1 ms (Top 100.0%) | Memory: 2.20 MB (Top 50.0%)

impl Solution {
    pub fn uncommon_from_sentences(s1: String, s2: String) -> Vec<String> {
        let mut map = std::collections::HashMap::new();
        s1.split(' ')
            .chain(s2.split(' '))
            .for_each(|s| *map.entry(s).or_insert(0) += 1);
        map.iter()
            .filter_map(|(key, val)| match *val == 1 {
                true => Some((*key).to_string()),
                false => None,
            })
            .collect::<Vec<_>>()
    }
}
