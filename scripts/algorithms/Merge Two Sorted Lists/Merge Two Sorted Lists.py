class Solution:
	def mergeTwoLists(self, l: Optional[ListNode], r: Optional[ListNode]) -> Optional[ListNode]:

		ret = start = ListNode()
		while l and r:

			if l.val < r.val:
				start.next = l
				l = l.next
			else:
				start.next = r
				r = r.next

			start = start.next
		start.next = l or r

		return ret.next