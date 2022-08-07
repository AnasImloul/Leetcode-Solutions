class Solution {
    ListNode* ListCreation(vector<int> ans){
        ListNode* n1 = new ListNode(ans[0]);
        ListNode* head = n1;
        ListNode* tail = n1;
        for(int i = 1; i < ans.size(); i++){
            ListNode* newNode = new ListNode(ans[i]);
            tail->next = newNode;
            tail = newNode;
        }
        return head;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0){
            return NULL;
        }
        vector<int> ans;
        for(int i = 0; i < lists.size(); i++){
            ListNode* head = lists[i];
            while(head != NULL){
                ans.push_back(head->val);
                head = head->next;
            }
        }
        if(ans.size() == 0){
            return NULL;
        }
        sort(ans.begin(), ans.end());
        ListNode* anshead = ListCreation(ans);
        ans.clear();
        return anshead;
    }
};
