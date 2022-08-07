class Solution {
public:
	ListNode* rotateRight(ListNode* head, int k) {
	  
		if(head == nullptr || head->next == nullptr || k == 0) return head;
		
		ListNode* node = head;
		int s = 1;
		
		while(node->next != nullptr){
			s++;
			node = node->next;
		}
		
		node->next = head;
		k = k%s;
		
		while(--s >= k){
			node = node->next;
		}        
		
		ListNode* res = node->next;
		node->next = nullptr;
		return res;
	}
};