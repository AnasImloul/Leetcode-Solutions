// Runtime: 1 ms (Top 69.17%) | Memory: 43.9 MB (Top 66.95%)
class Solution {
    public ListNode[] splitListToParts(ListNode head, int k) {
        ListNode[] arr=new ListNode[k];

        if(k<2 || head==null || head.next==null){
            arr[0]=head;
            return arr;
        }

        ListNode temp=head;
        int len=1;
        while(temp.next!=null){
            len++;
            temp=temp.next;
        }

        int partition= len/k; //no of part 3
        int extra=len%k; //extra node 1 0

        ListNode curr=head;
        ListNode prev=null;
        int index=0;
        while(head!=null){
            arr[index++]=curr;
            for(int i=0; i<partition && curr!=null ; i++){
                prev=curr;
                curr=curr.next;
            }
            if(extra>0){
                prev=curr;
                curr=curr.next;
                extra--;
            }
            head=curr;
            prev.next=null;

        }
     return arr;
    }
}