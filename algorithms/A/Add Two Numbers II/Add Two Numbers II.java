class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode res=new ListNode(0);
        ListNode curr=res;
         l1=reverseLinkedList(l1);
         l2=reverseLinkedList(l2);
        int carry=0;
        while(l1!=null||l2!=null||carry==1)
        {
            int sum=0;
            if(l1!=null)
            {
                sum+=l1.val;
                l1=l1.next;
            }
            if(l2!=null)
            {
                sum+=l2.val;
                l2=l2.next;
            }
            sum+=carry;
            carry = sum/10; 
            curr.next= new ListNode(sum % 10); 
            
            curr = curr.next; 
        }
        return reverseLinkedList(res.next);
    }
    public ListNode reverseLinkedList(ListNode head)
    {
        ListNode curr=head;
        ListNode prev=null;
        ListNode next;
        while(curr!=null)
        {
            next=curr.next;
            curr.next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
}
