class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        def number(head):
            ans = ''
            while head:
                ans+=str(head.val)
                head = head.next
            return int(ans) 
        temp = dummy = ListNode(0)
        for i in str(number(l1) + number(l2)):
            temp.next = ListNode(i)
            temp = temp.next
        return dummy.next
      

