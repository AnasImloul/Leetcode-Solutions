/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        int temp = node->val;
        node->val = node->next->val;
        node->next->val = temp;
        
        ListNode* delNode = node->next;
        node->next = node->next->next;
        delete delNode;
    }
};
