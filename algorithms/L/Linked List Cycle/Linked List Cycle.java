public class Solution {
    public boolean hasCycle(ListNode head) {
        ListNode fast = head;
        ListNode slow = head;
        boolean result = false;
        while(fast!=null && fast.next!=null){
            fast = fast.next.next;
            slow = slow.next;
                if(fast == slow){
                    result =  true;
                    break;
                }
        }
        return result;
    }
}
