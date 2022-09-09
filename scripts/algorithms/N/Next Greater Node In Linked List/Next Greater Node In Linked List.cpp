// Runtime: 1392 ms (Top 16.70%) | Memory: 41.2 MB (Top 71.62%)
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ans;
        ListNode* curr = head;
        if(head->next == NULL){
            ans.push_back(0);
            return ans;
        }

        while(curr != NULL){
            ListNode* next = curr->next;
            while(next != NULL){
                if(next->val > curr->val){
                    ans.push_back(next->val);
                    break;
                }
                next = next->next;
            }
            if(next == NULL){
                ans.push_back(0);
            }
            curr = curr->next;
        }
        return ans;
    }
};