// Runtime: 3 ms (Top 74.29%) | Memory: 7.5 MB (Top 64.02%)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * ListNode *next;
 * ListNode() : val(0), next(nullptr) {}
 * ListNode(int x) : val(x), next(nullptr) {}
 * ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    ListNode* reverse(ListNode* head)
    {
        ListNode* prev = NULL;
        while(head != NULL)
        {
            ListNode* temp = head->next;
            head->next = prev;
            prev = head;
            head = temp;
        }
        return prev;
    }

    ListNode* reverseN(ListNode* head,int right)
    {
        ListNode* temp = head;
        while(right != 1)
            temp = temp->next,right--;

        ListNode* temp2 = temp->next;
        temp->next = NULL;

        ListNode* ans = reverse(head);
        head->next = temp2;
        return ans;

    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {

          if(left == right)
              return head;

          if(left == 1)
          {
              return reverseN(head,right);
          }
          else
          {
              ListNode* temp = head;
              right--;
              while(left != 2)
              {
                  temp = temp->next;
                  left--;
                  right--;
              }
              ListNode* temp2 = reverseN(temp->next,right);
              temp->next = temp2;
              return head;
          }

         return NULL;

    }
};