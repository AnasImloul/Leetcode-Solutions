class Solution {
    public void reorderList(ListNode head) {
        if (head == null) return;
		
		// Find start of second list
        ListNode slow = head, fast = head;
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
		
        ListNode list1 = head;
        ListNode list2 = reverseList(slow.next); // slow.next is start of list2
        
        // Break first list from second list!
        slow.next = null; 
        
		// Merge list1 and list2
        while (list2 != null) {
            ListNode l1Next = list1.next;
            ListNode l2Next = list2.next;
            list2.next = list1.next;
            list1.next = list2;
            list1 = l1Next;
            list2 = l2Next;
        }
    }
    
    private ListNode reverseList(ListNode node) {
        if (node == null) return node;
        ListNode newHead = null, currNode = node;
        while (currNode != null) {
            ListNode backup = currNode.next;
            currNode.next = newHead;
            newHead = currNode;
            currNode = backup;
        }
        return newHead;
    }
}
