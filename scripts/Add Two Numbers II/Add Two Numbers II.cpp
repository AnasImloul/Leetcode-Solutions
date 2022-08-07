class Solution {
public:
    ListNode* reverseList(ListNode* head){
        if(head == NULL) return head;
        ListNode* ptr, *fptr, *prev;
        ptr = head;
        fptr = ptr->next;
        ptr-> next = NULL;
        while(fptr != NULL){
            prev = ptr;
            ptr= fptr;
            fptr = fptr->next;
            ptr->next = prev;
        }
        return ptr;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode();
        ListNode* ptr = head;
        l1 = reverseList(l1);
        l2 = reverseList(l2);
        int carry = 0;
        while(l1 && l2){ 
            ptr->next = new ListNode();
            ptr = ptr->next;
            ptr->val = l1->val + l2->val  + carry;
            carry = ptr->val/10;
            ptr->val = ptr->val % 10;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1){ 
            ptr->next = new ListNode();
            ptr = ptr->next;
            ptr->val = l1->val + carry;
            carry = ptr->val/10;
            ptr->val = ptr->val % 10;
            l1 = l1->next;
        }
        while(l2){ 
            ptr->next = new ListNode();
            ptr = ptr->next;
            ptr->val = l2->val  + carry;
            carry = ptr->val/10;
            ptr->val = ptr->val % 10;
            l2 = l2->next;
        }
        if(carry){
            ptr->next = new ListNode();
            ptr = ptr->next;
            ptr->val = carry;
        }
        head = reverseList(head->next);
        return head;
    }
};
