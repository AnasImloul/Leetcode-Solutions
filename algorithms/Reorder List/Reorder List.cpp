class Solution {
public:
    ListNode* solve(ListNode* head,ListNode* temp){
        if(temp==NULL)return head;
        ListNode* curr=solve(head,temp->next);
        if(!curr)return NULL;
        if(curr==temp){
            curr->next=NULL;
            return nullptr;
        }
        if(curr->next==temp){
            temp->next=nullptr;
            return NULL;
        }
        temp->next=curr->next;
        curr->next=temp;
        curr=temp->next;
        return curr;
    }
    void reorderList(ListNode* head) {
        solve(head,head);
    }
};
