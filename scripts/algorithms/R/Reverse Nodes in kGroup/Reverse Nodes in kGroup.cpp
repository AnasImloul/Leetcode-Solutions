// Runtime: 7 ms (Top 92.91%) | Memory: 11.80 MB (Top 41.47%)

class Solution {
    int getLengthOfLinkedList(ListNode *head)
    {
        ListNode *ptr = head;
        int cnt=0;
        while(ptr)
        {
            cnt++;
            ptr=ptr->next;
        }
        return cnt;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        if(!head)
            return NULL;
    
        int len = getLengthOfLinkedList(head);
        if(len<k)
            return head;
        
        int numberOfGroupsToReverse = len/k;
        
        ListNode *dummyNode = new ListNode(-1);
        dummyNode->next = head;
        ListNode *start = dummyNode;

        ListNode *pre,*remaining,*next;
        for(int i=0;i<numberOfGroupsToReverse;i++)
        {
            pre = NULL;
            remaining = head;
            for(int j=0;j<k;j++)
            {
                next = head->next;
                head->next = pre;
                pre=head;
                head=next;
            }
            start->next = pre;
            remaining->next = head;
            start = remaining;
        }
        
        return dummyNode->next;
    }
};
