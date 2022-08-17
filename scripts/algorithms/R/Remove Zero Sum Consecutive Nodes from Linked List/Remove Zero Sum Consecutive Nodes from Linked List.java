class Solution {
    public ListNode removeZeroSumSublists(ListNode head) {
        Map<ListNode, Integer> nodeSum = new HashMap<>();    //record the prefix sum of each node
        Map<Integer, ListNode> sumNode = new HashMap<>();    //record the prefix sum corresponding node
        ListNode n = head;
        int sum = 0;    //prefix sum
        while (n != null) {
            sum += n.val;
            if (sum != 0 && sumNode.containsKey(sum)) {
			   //means for e.g. `1 -> 3 -> -3 ->...`, prefix sum is `[1,4,1]`
			   //the first prefix sum `1` is recorded in map, then refactor the list to `1->...` ,
			   //and remove the prefix sum recording, so that`[1,4,1] -> [1]`
                for (ListNode p = sumNode.get(sum).next; p != n; p = p.next)
                    sumNode.remove(nodeSum.remove(p));
                sumNode.get(sum).next = n.next;
            } else if (sum == 0) {
				//means for e.g. `1 -> 3 -> -4 ->...`, prefix sum is `[1,4,0]`
				//`0` means the whole list before cur node (including cur node) can be removed.
                for (ListNode p = head; p != n; p = p.next)
                    sumNode.remove(nodeSum.remove(p));
                head = n.next;
            } else {
                nodeSum.put(n, sum);
                sumNode.put(sum, n);
            }
            n = n.next;
        }
        return head;
    }
}
