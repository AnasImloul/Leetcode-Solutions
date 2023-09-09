// Runtime: 223 ms (Top 92.5%) | Memory: 116.48 MB (Top 63.7%)

class Solution {
    int doubleItHelper(ListNode* newHead)
    {
        if(!newHead)
            return 0;
        int carry = doubleItHelper(newHead->next);
        
        int curSum = newHead->val;
        curSum*=2;
        curSum+=carry;
        
        int reminder = curSum%10;
        int newCarry = curSum/10;
        
        newHead->val = reminder;
        
        return newCarry;
    }
public:
    ListNode* doubleIt(ListNode* head)
    {
        ListNode* newHead = head;
        int carry = doubleItHelper(newHead);
        if(carry!=0)
        {
            ListNode* temp = new ListNode(carry);
            temp->next = newHead;
            newHead = temp;
        }
        return newHead;
    }
};