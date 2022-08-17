class Solution {
public:
    int getDecimalValue(ListNode* head) {
        ListNode* temp = head;
        int count = 0;
        while(temp->next != NULL){
            count++;
            temp = temp->next;
        }
        temp = head;
        int ans = 0;
        while(count != -1){
            ans += temp->val * pow(2,count);
            count--;
            temp = temp->next;
        }
        return ans;
    }
};
