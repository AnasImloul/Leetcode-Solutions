// Runtime: 131 ms (Top 100.0%) | Memory: 9.09 MB (Top 100.0%)

impl Solution {
    pub fn reverse_even_length_groups(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let mut head = head;
        let mut data = vec![];
        let mut ret = None;
        let mut tail = &mut ret;
        let mut sz = 1usize;
        
        while let Some(mut node) = head {
            head = node.next.take();
            node.next = None;
            data.push(node);
            if data.len() == sz {
                if sz % 2 == 0 { data.reverse(); }
                for p in data {
                    tail = &mut tail.insert(p).next;
                }
                data = vec![];
                sz += 1;
            }
        }
        
        if data.len() > 0 {
            if data.len() % 2 == 0 { data.reverse(); }
            for p in data {
                tail = &mut tail.insert(p).next;
            }
        }
        
        ret
    }
}