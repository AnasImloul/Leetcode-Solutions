// Runtime: 3 ms (Top 99.02%) | Memory: 11.4 MB (Top 15.63%)
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* k=new ListNode();
        ListNode *root=k,*cur=head;
        while(cur!=NULL)
        {
            ListNode *t=cur;
            while(t->next!=NULL && t->next->val==t->val)
                t=t->next;
            if(t==cur)
            {
            if(root==NULL)
                root->val=t->val;
            else
            {
                ListNode* p=new ListNode(t->val);
                root->next=p;
                root=root->next;
            }
            }
            cur=t->next;
        }
        return k->next;
    }
};