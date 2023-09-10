// Runtime: 1 ms (Top 70.8%) | Memory: 1.96 MB (Top 87.5%)

impl Solution {
    pub fn get_decimal_value(head: Option<Box<ListNode>>) -> i32 {
        let mut cur_node = &head;
        let mut v = Vec::new();
        while let Some(node) = cur_node {
            v.push(node.val);
            cur_node = &node.next;
        }

        v.iter()
            .rev()
            .enumerate()
            .fold(0, |acc, (ind, val)| acc + *val * (1 << ind))
    }
}