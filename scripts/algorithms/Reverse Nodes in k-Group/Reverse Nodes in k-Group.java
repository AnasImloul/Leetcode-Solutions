class Solution {
    public ListNode reverseKGroup(ListNode head, int k) {
        
        if(k<=1 ||head==null||head.next==null)return head;
        
        //Finding the length of Lined List.
        
        int length=1;
        ListNode temp=head;
        while(temp.next!=null){
            length++;
            temp=temp.next;
        }
        
        //Step 1 : Set Current and Previous Pointer.
        
        ListNode curr=head;
        ListNode prev=null;
        
        // Step 3 : Run a while Loop until Current is Null or Count < k.
        
        while(curr!=null){
            
            //Step 4 : Make Last and NewEnd pointers for connecting.
            
            ListNode next=curr.next;            
            ListNode last=prev;
            ListNode newEnd=curr;
            
            //Step 5 : Reverse K Nodes
            
            for(int i=0; curr!=null && i<k; i++){
                curr.next=prev;
                prev=curr;
                curr=next;
                
                if(next!=null){
                    next=next.next;
                }
            }
            
            if(last!=null){
                last.next=prev;
            }
            else{
                head=prev;
            }
            
            newEnd.next=curr;
            prev=newEnd;
            
            //Step 6 : Decrease Count by k Nodes and if count is less than k then break loop
            
            length=length-k;
            if(length<k){
                break;
            }
        }
        return head;
    }
}
