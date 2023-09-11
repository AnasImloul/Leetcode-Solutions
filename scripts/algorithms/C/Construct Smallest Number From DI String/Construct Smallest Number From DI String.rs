// Runtime: 1 ms (Top 71.4%) | Memory: 2.15 MB (Top 57.1%)

impl Solution {
	pub fn smallest_number(pattern: String) -> String {
		let mut a = "123456789".chars().collect::<Vec<char>>()[..pattern.len() + 1].to_vec();
		let mut s = vec![];
		for (i, c) in pattern.chars().enumerate() {
			if s.is_empty() || pattern.chars().nth(i - 1) != Some(c) { s.push(1); }
			else { *s.last_mut().unwrap() += 1; }
		}
		let mut i = 0;
		for c in s {
			if pattern.chars().nth(i) == Some('D') {
				for d in 0..(c + 1) / 2 { a.swap(i + d, i + c - d); }
			}
			i += c;
		}
		a.iter().collect()
	}
}