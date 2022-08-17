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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* n1 = new ListNode();
         ListNode *temp=head;
         ListNode *p=head;
        ListNode *q=n1;
        n1->next=head;
        int count;
        while(temp)
        { 
         
            if(n>0){
                n--;
            }
            else if(n==0){
            cout<val;
            p=p->next;
            q=q->next;
            }
               temp=temp->next;
        }
        q->next=p->next;
        delete p;
    return n1->next;
    }
};
