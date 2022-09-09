// Runtime: 7 ms (Top 31.33%) | Memory: 218.3 MB (Top 51.88%)
class Solution {
    public ListNode deleteMiddle(ListNode head) {
        // Base Condition
        if(head == null || head.next == null) return null;
        // Pointers Created
        ListNode fast = head;
        ListNode slow = head;
        ListNode prev = head;

        while(fast != null && fast.next != null){
            prev = slow;
            slow = slow.next;
            fast = fast.next.next;
        }
        prev.next = slow.next;
        return head;
    }
}