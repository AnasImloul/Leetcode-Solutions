class Solution:

    def __init__(self, head: Optional[ListNode]):
        self.lst = []
        while head:
            self.lst.append(head.val)
            head = head.next

    def getRandom(self) -> int:
        return random.choice(self.lst)
