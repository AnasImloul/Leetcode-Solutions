// Runtime: 721 ms (Top 25.59%) | Memory: 45.5 MB (Top 95.29%)
class Solution {
    public int[] nextLargerNodes(ListNode head) {
        ListNode length=head;
        int l=0;
        while(length!=null)
        {
            length=length.next;
            l++;
        }
        int[] res=new int[l];
        int i=0;
        ListNode temp=head;

        while(temp!=null)
        {
            ListNode temp1=temp.next;
            int max=temp.val;

            while(temp1!=null)
            {
                if(temp1.val>max)
                {
                    max=temp1.val;
                    res[i]=max;
                    break;
                }

                temp1=temp1.next;
            }
            temp=temp.next;
            i++;
        }
        return res;
    }
}