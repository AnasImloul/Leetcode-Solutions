class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode *prev=head,*cur=head->next;
        while(cur){
            ListNode *tmp=head,*pt=NULL;
            while(tmp!=cur and tmp->val < cur->val){
                pt=tmp;
                tmp=tmp->next;
            }
            if(tmp==cur){
                prev=prev->next;
                cur=cur->next;
                continue;
            }
            prev->next=cur->next;
            if(!pt){
                cur->next=head;
                head=cur;
            }
            else{
                pt->next=cur;
                cur->next=tmp;
            }
            cur=prev->next;
        }
        return head;
    }
};
