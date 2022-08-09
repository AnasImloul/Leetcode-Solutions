class Solution:
    def sortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        temp = ListNode()
        sort = temp
        val = []
        while head:
            val.append(head.val)
            head = head.next
        val = sorted(val)
        for i in val:
            curr = ListNode(i)
            sort.next = curr
            sort = sort.next
        return temp.next

