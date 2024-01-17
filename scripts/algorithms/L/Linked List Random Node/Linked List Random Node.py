// Runtime: 53 ms (Top 95.6%) | Memory: 20.10 MB (Top 30.35%)

class Solution:
    def __init__(self, head: Optional[ListNode]):
        self.ll=[]
        while head:
            self.ll.append(head.val)
            head=head.next
    def getRandom(self) -> int:
        return self.ll[randint(0, len(self.ll)-1)]
