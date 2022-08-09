class Solution {
    public ListNode middleNode(ListNode head) {
        
        ListNode temp = head;
        int size = 0;
        while(temp!=null){
            size++;
            temp = temp.next;
        }
        int mid = size/2;
        temp = head;
        for(int i=0;i<mid;i++){
            temp = temp.next;
        }
        
        return temp;
        
    }
}
