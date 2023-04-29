class Solution:
    def nextLargerNodes(self, head: Optional[ListNode]) -> List[int]:
        stack = []
        ans = []
        node = head
        
        i = 0
        while node is not None:
            while stack and stack[-1][0] < node.val:
                ans[stack[-1][1]] = node.val
                stack.pop()
            
            stack.append((node.val, i))
            ans.append(0)
            i += 1
            node = node.next
            
        return ans