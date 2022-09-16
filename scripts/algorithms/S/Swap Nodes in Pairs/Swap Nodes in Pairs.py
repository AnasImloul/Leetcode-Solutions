# Runtime: 38 ms (Top 82.22%) | Memory: 13.9 MB (Top 64.44%)

class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head:
            return head
        dummy = ListNode(None, head)
        prev, curr_1, curr_2 = dummy, head, head.next
        while curr_1 and curr_2:
            # 1. define temp nodes, temp nodes are comprised of 1 prev node, and multiple curr nodes. The while condition checks those curr nodes only.
            node_0 = prev
            node_1 = curr_1
            node_2 = curr_2
            node_3 = curr_2.next

            # 2. swap nodes using temp nodes
            node_0.next = node_2
            node_1.next = node_3
            node_2.next = node_1

            # 3. move temp nodes to the next window
            prev = node_1
            curr_1 = node_3
            curr_2 = node_3.next if node_3 else None

        return dummy.next