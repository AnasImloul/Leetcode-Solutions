// Runtime: 0 ms (Top 100.00%) | Memory: 41.5 MB (Top 99.13%)
/**
 * Definition for singly-linked list.
 * public class ListNode {
 * int val;
 * ListNode next;
 * ListNode() {}
 * ListNode(int val) { this.val = val; }
 * ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode reverseList(ListNode head) {

        if(head == null || head.next == null) return head;

        ListNode curr = head;
        ListNode temp = null, next = curr.next;
        curr.next = null;

        while(curr !=null && next !=null)
        {
            // before cutting off link between next & its next, save next.next
            temp = next.next;
            // let next point to curr
            next.next = curr;

            curr = next;
            next = temp;

        }

        return curr;

    }
}