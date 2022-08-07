class Solution {
    public ListNode insertionSortList(ListNode head) {
        ListNode cur = head;
        ListNode temp = new ListNode(-5001);
        ListNode prev = temp;
        while(cur != null){
            ListNode nxt = cur.next;
            if(prev.val >= cur.val)
                prev = temp;
            while(prev.next != null && prev.next.val < cur.val)
                prev = prev.next;
            cur.next = prev.next;
            prev.next = cur;
            cur = nxt;
        }
        return temp.next;
    }
}
