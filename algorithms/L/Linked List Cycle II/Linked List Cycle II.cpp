class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        map<ListNode*, int> m;
        int index = 0;
        while (head)
        {
            if (m.find(head) == m.end())
                m[head] = index;
            else 
                return (head);
            head = head->next;
            index++;       
        }
        return (NULL);
    }
};
