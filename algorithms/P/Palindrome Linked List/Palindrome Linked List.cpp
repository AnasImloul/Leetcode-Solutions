class Solution {
public:
    ListNode* reverse(ListNode* head)
    {
        ListNode* prev=nullptr;
        while(head)
        {
            ListNode* current=head->next;
            head->next=prev;
            prev=head;
            head=current;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
         if(!head || !head->next) return true;
        ListNode* tort=head;
        ListNode* hare=head;
        while(hare->next && hare->next->next)
        {
            tort=tort->next;
            hare=hare->next->next;
        }
        tort->next=reverse(tort->next);
         tort=tort->next;
        ListNode* dummy=head;
        while(tort)
        {
            if(tort->val!=dummy->val)
                return false;
            tort=tort->next;
            dummy=dummy->next;
        }
        return true;
    }
};

Time Complexity: O(n/2)+O(n/2)+O(n/2)
Space Complexity: O(1)
