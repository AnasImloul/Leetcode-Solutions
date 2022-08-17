class Solution {
    public ListNode mergeInBetween(ListNode list1, int a, int b, ListNode list2) {
        ListNode left = list1;
        for (int i = 1; i < a; i++)
            left = left.next;
        
        ListNode middle = left;
        for (int i = a; i <= b; i++)
            middle = middle.next;
        
		left.next = list2;
        while (list2.next != null)
            list2 = list2.next;
        
        list2.next = middle.next;
        return list1;
    }
}
