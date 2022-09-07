// Runtime: 0 ms (Top 100.00%) | Memory: 41.4 MB (Top 64.79%)
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
    public int getDecimalValue(ListNode head) {
        head = reverse(head);
        int ans = 0;
        int pow = 0;
        ListNode temp = head;
        while(temp != null){
            ans = ans + temp.val * (int) Math.pow(2,pow++);
            temp = temp.next;
        }

        return ans;
    }
    public ListNode reverse(ListNode head){
        ListNode prev = null;
        ListNode pres = head;
        ListNode Next = pres.next;

        while(pres != null){
            pres.next = prev;
            prev = pres;
            pres = Next;
            if(Next != null){
                Next = Next.next;
            }
        }

        head = prev;
        return head;
    }
}