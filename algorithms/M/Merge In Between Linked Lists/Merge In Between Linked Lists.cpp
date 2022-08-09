class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        
        int jump1 = 1;
        ListNode *temp1 = list1;
        while (jump1 < a){
            temp1 = temp1->next;
            jump1++;
        }                                //Gets the pointer to a
        
		int jump2 = 1;
        ListNode *temp2 = list1;
        while(jump2 <= b){
            temp2 = temp2->next;
            jump2++;
        }                                //Gets the pointer to b
        
		ListNode *temp3=list2;
        while(temp3->next != NULL){
            temp3=temp3->next;
        }                               //Gets the pointer to the tail of list2
        
		
		temp1->next=list2;              //set the next pointer of a to the head of list2
        
		temp3->next = temp2->next;      //set next of tail of list2 to the pointer to b
        
		return list1;                   //return the original list i.e. list1
        
    }
};
