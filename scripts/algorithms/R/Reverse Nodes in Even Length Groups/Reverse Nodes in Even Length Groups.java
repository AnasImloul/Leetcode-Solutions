// Runtime: 32 ms (Top 20.66%) | Memory: 252.2 MB (Top 80.33%)
// This Question can be solved easily using two standard methods of LinkedList
// 1) addFirst (it adds node in front of the LinkedList)
// 2) addLast (it adds node in end of the LinkedList)

class Solution {

    static ListNode oh;
    static ListNode ot;
    static ListNode th;
    static ListNode tt;

    public ListNode reverseEvenLengthGroups(ListNode head) {

        oh = null;
        ot = null;
        th = null;
        tt = null;

        if(head == null || head.next == null)
            return head;

        int size = length(head);
        int idx = 1;
        ListNode curr = head;
        int group = 1;

        while(curr!=null)
        {
            int temp = size - idx + 1;
            if((temp>=group && group%2 == 0) || (temp<group && temp%2 == 0))
            {
                int k = group;
                while(k-->0 && curr!=null)
                {
                    ListNode t = curr.next;
                    curr.next = null;
                    addFirst(curr);
                    curr = t;
                    idx++;
                }
            }
            else
            {
                int k = group;
                while(k-->0 && curr!=null)
                {
                    ListNode t = curr.next;
                    curr.next = null;
                    addLast(curr);
                    curr = t;
                    idx++;
                }
            }

            if(oh==null && ot==null)
            {
                oh = th;
                ot = tt;
            }
            else
            {
                ot.next = th;
                ot = tt;
            }

            th = null;
            tt = null;
            group++;
        }

        return oh;
    }

    public int length (ListNode head)
    {
        if(head==null) return 0;
        ListNode curr = head;
        int k = 0;
        while(curr!=null)
        {
             k++;
            curr = curr.next;
        }
        return k;
    }

    public void addFirst(ListNode head)
    {
        if(tt == null && th == null)
        {
            th = head;
            tt = head;
        }
        else
        {
            head.next = th;
            th = head;
        }
    }

    public void addLast(ListNode head)
    {
        if(tt == null && th == null)
        {
            th = head;
            tt = head;
        }
        else
        {
            tt.next = head;
            tt = head;
        }
    }
}