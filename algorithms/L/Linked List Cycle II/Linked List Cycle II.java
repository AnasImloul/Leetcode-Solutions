public class Solution {
    public ListNode detectCycle(ListNode head) {
        if (head == null) return null;
        ListNode tortoise = head;
        ListNode hare = new ListNode();
        hare.next = head.next;
        while (hare != null && hare.next != null && hare != tortoise) {
            tortoise = tortoise.next;
            hare = hare.next.next;
        }
        if (hare == null || hare.next == null) return null;
        tortoise = head;
        while (tortoise != hare) {
            tortoise = tortoise.next;
            hare = hare.next;
        }
        return hare;
    }
}
