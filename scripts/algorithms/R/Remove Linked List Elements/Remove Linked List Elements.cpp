// Runtime: 27 ms (Top 83.86%) | Memory: 15.3 MB (Top 20.54%)
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *prv,*cur,*temp;
        while(head && head->val==val){
            cur=head;
            head=head->next;
            delete(cur);
        }
       if(head==NULL) return head;
        prv=head;
        cur=head->next;
        while(cur){
            if(cur->val==val){
                temp=cur;
                prv->next=cur->next;
                cur=cur->next;
                delete(temp);
            }
            else{
                prv=cur;
                cur=cur->next;
            }
        }
        return head;

    }
};