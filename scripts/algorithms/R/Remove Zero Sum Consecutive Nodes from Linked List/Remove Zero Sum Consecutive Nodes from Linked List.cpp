// Runtime: 28 ms (Top 27.29%) | Memory: 11.3 MB (Top 53.06%)
class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        unordered_map<int, ListNode*> m; // {prefix -> node}
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;
        dummy->next = head;
        int prefix = 0;
        while(cur){
            prefix += cur->val;
            if(m[prefix] != NULL){
                ListNode *t = m[prefix]->next;
                int sum = prefix;
                sum+=t->val;
                while(sum != prefix){
                    m.erase(sum);
                    t = t->next;
                    sum+= t->val;
                }
                m[prefix]->next = cur->next;
            }
            else m[prefix] = cur;
            cur = cur->next;
        }
        return dummy->next;
    }
};