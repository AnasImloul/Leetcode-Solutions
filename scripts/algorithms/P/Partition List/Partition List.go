// Runtime: 2 ms (Top 67.61%) | Memory: 2.40 MB (Top 64.32%)

func partition(head *ListNode, x int) *ListNode {
    before := &ListNode{}
    after := &ListNode{}
    before_curr := before
    after_curr := after
    
    for head != nil {
        if head.Val < x {
            before_curr.Next = head
            before_curr = before_curr.Next
        } else {
            after_curr.Next = head
            after_curr = after_curr.Next
        }
        head = head.Next
    }
    
    after_curr.Next = nil
    before_curr.Next = after.Next
    
    return before.Next
}
