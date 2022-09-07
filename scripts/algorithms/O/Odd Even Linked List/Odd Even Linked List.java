// Runtime: 0 ms (Top 100.00%) | Memory: 44.6 MB (Top 61.89%)
class Solution {
    public ListNode oddEvenList(ListNode head) {
        if(head == null) {
            return head;
        }
        ListNode result = head, evenHalf = new ListNode(0), evenHalfPtr = evenHalf;
        for(; head.next != null; head = head.next) {
            evenHalfPtr = evenHalfPtr.next = head.next;
            head.next = head.next.next;
            evenHalfPtr.next = null;
            if(head.next == null) {
                break;
            }
        }
        head.next = evenHalf.next;
        return result;
    }
}