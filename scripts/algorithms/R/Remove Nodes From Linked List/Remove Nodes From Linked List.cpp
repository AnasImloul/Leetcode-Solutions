class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        vector<int> v;
        ListNode* p = head,*q;
        while(p){
            while(!v.empty()&&v.back()<p->val)v.pop_back();
            v.push_back(p->val);
            p = p->next;
        }
        p = head;
        int i = 0, n = v.size();
        while(i<n){
            p->val = v[i++];
            v.pop_back();
            q = p;
            p = p->next;
        }
        q->next = NULL;
        return head;
    }
};