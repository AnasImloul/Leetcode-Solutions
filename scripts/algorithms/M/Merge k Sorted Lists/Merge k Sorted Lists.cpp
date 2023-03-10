class Solution {
public:
    struct compare
    {
        bool operator()(ListNode* &a,ListNode* &b)
        {
            return a->val>b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,compare>minh;
        for(int i=0;i<lists.size();i++)
        {
           if(lists[i]!=NULL) minh.push(lists[i]);
        }
        ListNode* head=new ListNode(0);
        ListNode* temp=head;
        while(minh.size()>0)
        {
            ListNode* p=minh.top();
            minh.pop();
            temp->next=new ListNode(p->val);
            temp=temp->next;
            if(p->next!=NULL) minh.push(p->next);
        }
        return head->next;
    }
};