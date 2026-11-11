// Runtime: 1 ms (Top 38.59%) | Memory: 2.30 MB (Top 36.24%)

impl Solution {
    pub fn add_two_numbers(l1: Option<Box<ListNode>>, l2: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        match (l1, l2) {
            (None, None) => None,
            (Some(n), None) | (None, Some(n)) => Some(n), 
            (Some(n1), Some(n2)) => {
                let sum = n1.val + n2.val;
                if sum < 10 {
                    Some(Box::new(ListNode {
                        val: sum,
                        next: Solution::add_two_numbers(n1.next, n2.next)
                    }))
                } else {
                    let carry = Some(Box::new(ListNode::new(1)));
                    Some(Box::new(ListNode {
                        val: sum - 10,
                        next: Solution::add_two_numbers(Solution::add_two_numbers(carry, n1.next), n2.next)
                    }))
                }
            }
        }
    }
}
