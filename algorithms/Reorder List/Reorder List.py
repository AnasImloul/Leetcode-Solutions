class Solution:
    def reverse(self , head):
        prev = None
        after = None
        curr = head
        while(curr):
            after = curr.next
            curr.next = prev
            prev = curr
            curr = after
        return prev
            
    def find_middle(self , head):
        slow = head
        fast = head
        while(fast and fast.next):
            fast = fast.next.next
            slow = slow.next
        return slow
        
    def reorderList(self, head: Optional[ListNode]) -> None:
        mid = self.find_middle(head)
        rev = self.reverse(mid)
        first = head
        second = rev
        
        while(second.next):
            temp = first.next
            first.next = second
            first = temp
            
            temp = second.next
            second.next = first
            second = temp
            
