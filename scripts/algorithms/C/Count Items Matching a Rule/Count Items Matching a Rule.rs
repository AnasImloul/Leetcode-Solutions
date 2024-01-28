// Runtime: 3 ms (Top 100.0%) | Memory: 4.00 MB (Top 100.0%)

impl Solution {
    pub fn count_matches(items: Vec<Vec<String>>, rule_key: String, rule_value: String) -> i32 {
        let mut ans = 0;

        for item in items.iter() {
            match rule_key.as_str() {
                "type" => if (item[0] == rule_value) { ans += 1 },
                "color" => if (item[1] == rule_value) { ans += 1 },
                "name" => if (item[2] == rule_value) { ans += 1 },
                _ => (),
            }
        }

        ans
    }
}
