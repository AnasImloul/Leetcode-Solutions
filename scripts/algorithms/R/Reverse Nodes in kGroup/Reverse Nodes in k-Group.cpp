// Runtime: 24 ms (Top 57.65%) | Memory: 11.5 MB (Top 29.97%)
class Solution {
    pair<ListNode* , ListNode*> get_rev_list(ListNode* root){
        ListNode *tail = root;
        ListNode *curr = root , *temp , *prev = NULL;

        while(curr != NULL){
            temp = curr -> next;
            curr -> next = prev;

            prev = curr;
            curr = temp;
        }

        return make_pair(prev , tail);
    }

    public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k == 1)
            return head;

        vector<pair<ListNode* , ListNode*>> store;

        ListNode *temp = head , *temp_head = head;
        int len = 0;

        while(temp != NULL){
            len++;

            if(len == k){
                ListNode *next_head = temp -> next;
                temp -> next = NULL;

                store.push_back(get_rev_list(temp_head));
                temp = next_head;
                len = 0;
                temp_head = next_head;
            }
            else
                temp = temp -> next;
        }

        if(len == k)
        store.push_back(get_rev_list(temp_head));

        for(int i = 1; i < store.size(); i++)
            store[i - 1].second -> next = store[i].first;

        if(len != k)
            store[store.size() - 1].second -> next = temp_head;

        return store[0].first;
    }
};