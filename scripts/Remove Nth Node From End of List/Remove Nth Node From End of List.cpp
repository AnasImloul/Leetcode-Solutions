class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode *temp,*temp1;
        int i=0;
        if(head==NULL)
            return head;
        temp=temp1=head;
        for(i=1;i<=n;i++){
            temp=temp->next;
        }
        if(temp==NULL){
            head=head->next;
            return head;
        }
        while(temp->next!=NULL){
            temp=temp->next;
            temp1=temp1->next;
        }
        
        temp1->next= temp1->next->next;
        return head;
        
    }
};
