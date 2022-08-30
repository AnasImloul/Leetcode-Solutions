// Runtime: 55 ms (Top 55.51%) | Memory: 71 MB (Top 93.72%)
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head1, *head2, *head3, *temp;
        head1=l1;
        head2 = l2;
        head3=NULL;
        int carry = 0, res = 0;
        while(head1 && head2){
            res = head1->val +head2->val + carry;
            carry = res/10;
            head1->val = res%10;
            if(!head3){
                head3 = head1;
                temp = head3;
            }
            else{
                temp->next = head1;
                temp = temp->next;
            }
            head1 = head1->next;
            head2 = head2->next;
        }
        while(head1){
            res = head1->val + carry;
            carry = res/10;
            head1->val = res%10;
            temp->next = head1;
            temp = temp->next;
            head1 = head1->next;
        }
        while(head2){
            res = head2->val + carry;
            carry = res/10;
            head2->val = res%10;
            temp->next = head2;
            temp = temp->next;
            head2 = head2->next;
        }
        if(carry){
            ListNode* result = new ListNode();
            result->val = carry;
            result->next = NULL;
            temp->next = result;
            temp = temp->next;
        }
        return head3;
    }
};