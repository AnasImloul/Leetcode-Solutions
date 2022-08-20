// Runtime: 0 ms (Top 100.00%) | Memory: 41.8 MB (Top 55.04%)

class Solution {
    public ListNode swapPairs(ListNode head) {
        ListNode dummy = new ListNode(0) , prev = dummy , curr = head;
        dummy.next = head;
        while(curr != null && curr.next != null){
            prev.next = curr.next;
            curr.next = curr.next.next ;
            prev.next.next = curr;
           curr = curr.next ;
            prev = prev.next.next;
        }
        return dummy.next;
    }
}
