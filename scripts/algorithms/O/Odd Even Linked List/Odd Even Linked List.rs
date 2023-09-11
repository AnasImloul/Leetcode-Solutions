// Runtime: 2 ms (Top 69.0%) | Memory: 2.37 MB (Top 83.3%)

impl Solution {
    pub fn odd_even_list(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let mut head = head;
        let mut odd = Box::new(ListNode::new(-1));
        let mut cur_odd = &mut odd;
        let mut even = Box::new(ListNode::new(-1));
        let mut cur_even = &mut even;
        let mut is_odd = true;
        while head.is_some() {
            if is_odd {
                cur_odd.next = head;
                cur_odd = cur_odd.next.as_mut()?;
                head = cur_odd.next.take();
            } else {
                cur_even.next = head;
                cur_even = cur_even.next.as_mut()?;
                head = cur_even.next.take();
            }
            is_odd = !is_odd;
        }
        cur_odd.next = even.next;
        return odd.next;
    }
}