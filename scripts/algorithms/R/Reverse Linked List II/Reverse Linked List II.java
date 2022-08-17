class Solution {
    public ListNode reverseBetween(ListNode head, int left, int right) {
        if(left==right) return head;
        ListNode last = null;
        ListNode present = head;
        
        for(int i=0; present != null && i<left-1;i++){
            last = present;
            present = present.next;
        }
        ListNode finalEnd = present;
        
        ListNode prev = last;
        ListNode next = present.next;
        
        for(int i=0; present != null && i<right-left+1;i++){
            present.next = prev;
            prev = present;
            present = next;
            if(next!= null){
                next = next.next;
            }
        }
        if(last != null){
            last.next = prev;
        }
        else{
            head = prev;
        } 
        finalEnd.next = present;
        return head;
    }
}
