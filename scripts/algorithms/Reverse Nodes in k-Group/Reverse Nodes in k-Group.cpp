  
  /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL){
            return NULL;
        }
        int size = 0;
        deque<int> s;
        ListNode* a = new ListNode(-1);
        ListNode* ans = a;
        while(head != NULL){
            if(size == k){
                while(!s.empty()){
                    ans->next = new ListNode(s.front());
                    ans = ans->next;
                    s.pop_front();
                }
                size = 0;
            }else{
                s.push_front(head->val);
                size+=1;
                head = head->next;
            }
        }
        if(size != k){
            while(!s.empty()){
                ans->next = new ListNode(s.back());
                ans = ans->next;
                s.pop_back();
            }
        }else{
            while(!s.empty()){
                ans->next = new ListNode(s.front());
                ans = ans->next;
                s.pop_front();
            }  
        }
        return a->next;
    }
};
  
