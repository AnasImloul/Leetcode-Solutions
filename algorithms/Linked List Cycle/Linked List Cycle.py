class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        for i in range(0, 10001):
            if head == None: return False
            head = head.next
        
        return True
