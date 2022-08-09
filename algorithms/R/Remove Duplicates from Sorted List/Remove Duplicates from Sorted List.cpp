class Solution {
public:
    // Recursive Approach
    ListNode* deleteDuplicates(ListNode* head){
        // base case
        if(head==NULL || head->next==NULL)
            return head;
        // 1-1-2-3-3
        //we are giving next pointer to recursion and telling it to get it done for me
        ListNode* newNode=deleteDuplicates(head->next); // 1-2-3-3
        // after recursion we will get-- 1-2-3
        
        //now we will compare the head node with the newNode 
        // if both are same then return the newNode
        //else return the current head
        if(head->val==newNode->val) 
            return newNode;
        else{
            head->next=newNode;
            return head;
        } 
    }
};


class Solution {
public:
    // Iterative Approach
    ListNode* deleteDuplicates(ListNode* head){
        if(head==NULL || head->next==NULL) return head;
        
        ListNode* temp =head;
        while(temp->next!=NULL){
            // if the 2 consecutive nodes are equal then just delete the in between
            if(temp->val==temp->next->val){
                temp->next=temp->next->next;
                //dont need to update the temp variable as there can be more than 2 duplicates
                // 1-1-1-1-2-3-4-4-NULL
            }
            else{
                temp=temp->next; //update the temp variable
            }
        }
        return head;
    }
};
