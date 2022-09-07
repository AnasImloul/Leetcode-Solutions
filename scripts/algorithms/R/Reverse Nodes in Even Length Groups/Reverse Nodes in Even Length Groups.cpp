// Runtime: 2456 ms (Top 6.39%) | Memory: 329.7 MB (Top 84.60%)
class Solution {
public:

    // Function to reverse a linked list
    ListNode* reverseList(ListNode* head) {
        if(!head)
            return head;
        ListNode* prev = NULL;
        while(head) {
            ListNode* temp = head -> next;
            head -> next = prev;
            prev = head;
            head = temp;
        }

        return prev;
    }

    ListNode* reverseEvenLengthGroups(ListNode* head) {
        // Creating a dummy node to avoid adding checks for the first node
        ListNode* dummy = new ListNode();
        dummy -> next = head;

        ListNode* prev = dummy;

        // Loop to determine the lengths of groups
        for(int len = 1; len < 1e5 && head; len++) {
            ListNode* tail = head;
            ListNode* nextHead;

            // Determining the length of the current group
            // Its maximum length can be equal to len
            int j = 1;
            while(j < len && tail && tail -> next) {
                tail = tail -> next;
                j++;
            }

            // Head of the next group
            nextHead = tail -> next;

            if((j % 2) == 0) {
                // If even sized group is found
                // Reversing the group and setting prev and head appropriately
                tail -> next = NULL;
                prev -> next = reverseList(head);
                prev = head;
                head -> next = nextHead;
                head = nextHead;
            } else {
                // If group is odd sized, then simply going towards the next group
                prev = tail;
                head = nextHead;
            }
        }

        // Returning the head
        return dummy -> next;
    }
};