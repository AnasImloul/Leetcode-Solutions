// Runtime: 101 ms (Top 23.35%) | Memory: 14.3 MB (Top 98.77%)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * ListNode *next;
 * ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:

    //function to get length of linked list
    int getLength(ListNode *head)
    {
        //initial length 0
        int l = 0;

        while(head != NULL)
        {
            l++;
            head = head->next;
        }
        return l;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        //ptr1 & ptr2 will move to check nodes are intersecting or not
        //ptr1 will point to the list which have higher length, higher elements (big list)
        //ptr2 will point to small list
        ListNode *ptr1,*ptr2;

        //fetching length of both the list,as we want a node that both ptr points simultaneously
        //so if both list have same length of nodes, they travel with same speed, they intersect
        //if diff legths, it'll be difficult for us to catch
        //so by substracting list with higher length with lower length
        //we get same level of length, from which both ptr start travaeling, they may get intersect
        int length1 = getLength(headA);
        int length2 = getLength(headB);

        int diff = 0;

        //ptr1 points to longer list
        if(length1>length2)
        {
            diff = length1-length2;
            ptr1 = headA;
            ptr2 = headB;

        }
        else
        {
            diff = length2 - length1;
            ptr1 = headB;
            ptr2 = headA;
        }

        //till diff is zero and we reach our desired posn
        while(diff)
        {
            //incrementing ptr1 so that it can be at a place where both list have same length

            ptr1 = ptr1->next;

            if(ptr1 == NULL)
            {
                return NULL;
            }

            diff--;
        }

        //traverse both pointers together, till any of them gets null
        while((ptr1 != NULL) && (ptr2 != NULL))
        {
            //at any point, both point to same node return it
            if(ptr1 == ptr2)
            {
                return ptr1;
            }

            //increment both pointers, till they both be NULL
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }

        //if not found any intersaction, return null
        return NULL;

     }
};