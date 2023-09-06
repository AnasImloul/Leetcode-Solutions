// Runtime: 2 ms (Top 92.2%) | Memory: 43.00 MB (Top 67.8%)

class Solution {
    public ListNode removeZeroSumSublists(ListNode head) {
        
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        
        int prefix = 0;
        ListNode curr = dummy;
        Map<Integer, ListNode> seen = new HashMap<>();
        seen.put(prefix, dummy);
        
        while (curr != null) {
            prefix += curr.val;
            seen.put(prefix, curr);
            curr = curr.next;
        }
        
        prefix = 0;
        curr = dummy;
        while (curr != null) {
            prefix += curr.val;
            curr.next = seen.get(prefix).next;
            curr = curr.next;
        }
        
        return dummy.next;
    }
}