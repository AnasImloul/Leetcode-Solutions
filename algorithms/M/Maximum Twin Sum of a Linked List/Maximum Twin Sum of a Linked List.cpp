class Solution {
public:
    ListNode* reverse(ListNode* head){
        ListNode* prev=NULL,*curr=head,*nextstop;
        while(curr){
            nextstop=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextstop;
        }
        return prev;
    }
    
    ListNode* findMiddleNode(ListNode* head){
        ListNode* slowptr=head,*fastptr=head->next;
        while(fastptr&&fastptr->next){
            slowptr=slowptr->next;
            fastptr=fastptr->next->next;
        }
        return slowptr;
    }
    
    int pairSum(ListNode* head) {
        int ans=0;
        
        ListNode* midNode=findMiddleNode(head);
        ListNode* head2=reverse(midNode->next);
        
        midNode->next=NULL;
        
        
        ListNode* p1=head,*p2=head2;
        while(p1&&p2){
            ans=max(ans,p1->val+p2->val);
            p1=p1->next;
            p2=p2->next;
        }
        
        midNode->next=reverse(head2);
        
        return ans;
    }
};

