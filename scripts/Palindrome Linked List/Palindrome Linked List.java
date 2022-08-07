class Solution {
    public boolean isPalindrome(ListNode head) {
        
        ListNode mid = getMiddle(head);
        ListNode headSecond = reverse(mid);
        ListNode reverseHead = headSecond;
        
        while(head != null && headSecond != null){
            if(head.val != headSecond.val){
                break;
            }
            head = head.next;
            headSecond = headSecond.next;
        }
        reverse(reverseHead);
        
        return head==null || headSecond == null;
    }
    
    public ListNode reverse(ListNode head){
        if(head==null) return head;
        ListNode prev = null;
        ListNode present = head;
        ListNode next = head.next;
        while(present != null){
            present.next = prev;
            prev = present;
            present = next;
            if(next!=null)
            next = next.next;
        }
        return prev;
    }
    
    public ListNode getMiddle(ListNode head){
        ListNode temp = head;
        int count = 0;
        while(temp!=null){
            temp = temp.next;
            count++;
        }
        int mid = count/2;
        temp = head;
        for(int i=0; i<mid;i++){
            temp = temp.next;
        }
        return temp;
    }
}
