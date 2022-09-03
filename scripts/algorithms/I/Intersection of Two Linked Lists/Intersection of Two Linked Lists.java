// Runtime: 1 ms (Top 99.75%) | Memory: 55.6 MB (Top 36.20%)
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        ListNode tempA = headA, tempB = headB;
        int lenA = 0, lenB = 0;
        while (tempA != null) {
            lenA++;
            tempA = tempA.next;
        }
        while (tempB != null) {
            lenB++;
            tempB = tempB.next;
        }
        tempA = headA; tempB = headB;
        if (lenB > lenA) {
            for (int i = 0; i < lenB - lenA; i++) {
                tempB = tempB.next;
            }
        } else if (lenA > lenB) {
            for (int i = 0; i < lenA - lenB; i++) {
                tempA = tempA.next;
            }
        }
        while (tempA != null && tempA != tempB) {
            tempA = tempA.next;
            tempB = tempB.next;
        }
        return tempA;
    }
}