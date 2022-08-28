// Runtime: 0 ms (Top 100.00%) | Memory: 41.5 MB (Top 99.82%)
class Solution {
    public ListNode deleteDuplicates(ListNode head) {

        if (head == null) {
            return head;
        }

        ListNode result = head;

        while (result != null) {
            if (result.next == null) {
                break;
            }

            if (result.val == result.next.val) {
                result.next = result.next.next;
            } else {
                result = result.next;
            }
        }

        return head;
    }
}