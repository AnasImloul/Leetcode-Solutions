class Solution:
    def sortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        store = []
        curr = head
        while curr:
            store.append(curr.val)
            curr = curr.next
        store.sort()
        dummyNode = ListNode(0)
        temp = dummyNode
        
        for i in store:
            x = ListNode(val = i)
            temp.next = x
            temp = x
        return dummyNode.next