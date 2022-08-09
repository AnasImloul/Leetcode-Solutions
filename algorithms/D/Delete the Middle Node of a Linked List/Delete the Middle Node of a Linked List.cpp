**Intution**- we know that we can find middle node using two pointer fast and slow. 
 After we iterate through linkedlist slow pointer is our middle node and since we need to delete it
 we only need pointer to its previous node and then just simply put next to next node in previous node.
 Woahh ! you are done with deleting middle NODE;

class Solution {
public:
	ListNode* deleteMiddle(ListNode* head) {
		   if(head->next==nullptr) return nullptr;
		   ListNode *f=head;
		   ListNode *s=head,*prev;
		  while(f!=nullptr && f->next!=nullptr){
			  f=f->next->next;
			  prev=s;
			  s=s->next;
		  }
		prev->next=prev->next->next;
		return head;
	}
};