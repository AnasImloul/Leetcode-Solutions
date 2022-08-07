class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        PriorityQueue<Integer> pq = new PriorityQueue<>((a, b) -> b - a);
        
        for(ListNode l : lists) {
            while(l != null) {
                pq.add(l.val);
                l = l.next;
            }
        }
        
        ListNode ans = null;
        while(!pq.isEmpty()) {
            ListNode temp = new ListNode(pq.poll());
            temp.next = ans;
            ans = temp;
        }
        
        return ans;
    }
}