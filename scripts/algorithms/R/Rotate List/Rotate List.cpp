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
// like if it is useful to you
    ListNode* rotateRight(ListNode* head, int k) {
       if(head == NULL){
           return head;
       }
       vector<int> nums;
       ListNode *temp = head;
       while(temp != NULL){
           nums.push_back(temp->val);
           temp = temp->next;
       }
// if k greater than size;
        k = k%nums.size();
// rotating vector
     reverse(nums.begin(),nums.end());
     reverse(nums.begin(),nums.begin()+k);
     reverse(nums.begin()+k,nums.end());
// replace value of list    
 temp = head;
     for(int i = 0; i<nums.size();i++){
         temp->val = nums[i];
         temp = temp->next;
     }
     return head;
    }
};