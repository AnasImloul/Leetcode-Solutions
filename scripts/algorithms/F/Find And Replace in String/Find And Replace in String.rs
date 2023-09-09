// Runtime: 2 ms (Top 100.0%) | Memory: 2.09 MB (Top 100.0%)

use std::boxed::Box;

impl Solution {
    pub fn find_replace_string(s: String, indices: Vec<i32>, sources: Vec<String>, targets: Vec<String>) -> String {
        let s: Vec<char> = s.chars().collect();
        
        let mut idxs: Vec<(usize, usize, usize)> = indices.into_iter().enumerate()
        .zip(sources.into_iter())
        .map(|((i, idx), src)| (i, idx as usize, src))
        .filter(|(_, idx, src)| {
            (s.len() - *idx) >= src.len() && // First make sure that src does not overflow the string as it is a less expensive preliminary check
            s.iter().skip(*idx) // Next we lazily check whether s[idx..] has src as its prefix
            .zip(src.chars()).all(|(&ch, src_ch)| src_ch == ch)
        }).map(|(i, idx, src)| {
            (i, idx, src.len()) // if so we keep track of the src length and the index from which we performed prefix matching
        })
        .collect();
        
        idxs.sort_by_key(|&(i, idx, lsrc)| idx); // we sort by index and we go from left to right
        
        let start: Box<dyn Iterator<Item = char>> = Box::new(std::iter::empty()); // we build our iterator using dynamic dispatch starting from an empty iterator
        
        let (it, last_idx) = idxs.into_iter()
        .fold((start, 0), |(iter_acc, s_next), (i, idx, lsrc)| {
            (Box::new(iter_acc
                .chain(s[s_next..idx].iter().cloned()) // we accumulate the original characters in s from s_next..idx
                .chain(targets[i].chars())), // we then need to accumulate the targets[i] characters
                idx+lsrc // the next index to start replacing characters of s from would be idx+lsrc, which is the length of sources[i]
            )
        });
        
        let it = if last_idx < s.len() {
            Box::new(it.chain(s[last_idx..].iter().cloned())) // finally if we have some remaining characters in s then we accumulate those as well
        } else {
            it
        };
        
        it.collect() // finally we collect all the lazily accumulated iterators to form our result
    }
}