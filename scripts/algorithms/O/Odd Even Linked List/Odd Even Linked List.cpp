// Runtime: 19 ms (Top 54.79%) | Memory: 10.4 MB (Top 74.28%)
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL || head->next->next == NULL){
            return head;
        }
        ListNode *first = head;
        ListNode *second = head->next;
        ListNode *last = head;
        int count = 1;
        while(last->next != NULL){
            last = last->next;
            count++;
        }

        int n = count/2;
        while(n != 0){
            first->next = second->next;
            last->next = second;
            second->next = NULL;
            first = first->next;
            last = second;
            second = first->next;
            n--;
        }
        return head;
    }
};