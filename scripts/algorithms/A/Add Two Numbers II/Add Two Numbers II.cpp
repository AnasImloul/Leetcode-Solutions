/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverse(ListNode* l1){
        if(l1==NULL||l1->next==NULL){
            return l1;
        }
        ListNode* ans=reverse(l1->next);
        l1->next->next=l1;
        l1->next=NULL;
        return ans;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       ListNode* l11= reverse(l1);
       ListNode* l22= reverse(l2);
        ListNode* dummy=new ListNode(0);
        ListNode* curr=dummy;
        int carry=0;
        int sum=0;
        while(l11||l22||carry!=0){
            int x=l11?l11->val:0;
            int y=l22?l22->val:0;
            sum=x+y+carry;
            carry=sum/10;
            curr->next=new ListNode(sum%10);
            curr=curr->next;
            l11=l11?l11->next:nullptr;
            l22=l22?l22->next:nullptr;
        }
        dummy=dummy->next;
       dummy=reverse(dummy);
        return dummy;
    }
};