class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        
        // declare a dummy node
        
        ListNode* dummy = new ListNode(0);
        
        // point dummy -> next to head
        
        dummy -> next = head;
        
        // declare a tail pointer and point to dummy
        
        ListNode* tail = dummy;
        
        // move the curr pointer (k - 1) times
        
        // this will maintain a gap of (k - 1) between curr and tail pointer
        
        ListNode* curr = head;
        
        while(k > 1)
        {
            curr = curr -> next;
            
            k--;
        }
        
        // store the address in start pointer
        
        ListNode* start = curr;
        
        // maintaing a gap of (k - 1) between curr and tail, move both pointer
        
        while(curr)
        {
            tail = tail -> next;
            
            curr = curr -> next;
        }
        
        // store the address of kth node from end
        
        ListNode* end = tail;
        
        // swap the values
        
        swap(start -> val, end -> val);
        
        // dummy -> next will be head
        
        return dummy -> next;
    }
};