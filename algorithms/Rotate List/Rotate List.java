class Solution {
    public ListNode rotateRight(ListNode head, int k) {
        if(k<=0 || head==null || head.next==null){
            return head;
        }
        
        int length=1;
        ListNode first=head;
        ListNode curr=head;
        ListNode node=head;   
        while(node.next!=null){
            length++;
            node=node.next;
        }
        
        if(k==length){
            return head;
        }
        
        int n=length-(k%length);
        for(int i=0; i<n-1;i++){
            curr=curr.next;
        }
        
        node.next=head;  //5-->1
        head=curr.next;
        curr.next=null;
        
        return head;
    }
}
