// Runtime: 0 ms (Top 100.0%) | Memory: 2.10 MB (Top 65.38%)

impl Solution {
    pub fn partition(mut head: Option<Box<ListNode>>, x: i32) -> Option<Box<ListNode>> {
        let mut dummy1: Option<Box<ListNode>> = None;
        let mut dummy2: Option<Box<ListNode>> = None;
        let mut r1 = &mut dummy1;
        let mut r2 = &mut dummy2;
        while head.is_some() {
            if head.as_ref().unwrap().val < x {
                if r1.is_some() {
                    r1 = &mut r1.as_mut().unwrap().next;
                }
                std::mem::swap(r1, &mut head);
                std::mem::swap(&mut r1.as_mut().unwrap().next, &mut head);
            } else {
                std::mem::swap(r2, &mut head);
                std::mem::swap(&mut r2.as_mut().unwrap().next, &mut head);
                r2 = &mut r2.as_mut().unwrap().next;
            }
        }
        if r1.is_some() {
            r1.as_mut().unwrap().next = dummy2;
            dummy1
        } else {
            dummy2
        }
    }
}
