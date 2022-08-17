# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
from heapq import heappush,heappop
class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        heap = []
        heapq.heapify(heap)
        start = end = ListNode(-1)
        for i in lists:
            if i:
                heappush(heap,(i.val,id(i),i))
        while heap:
            val,iD,node = heappop(heap)
            end.next = node
            node = node.next
            end = end.next
            if node:
                heappush(heap,(node.val,id(node),node))
                
        return start.next
