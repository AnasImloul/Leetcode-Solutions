class Solution:
    def sortedListToBST(self, head: Optional[ListNode]) -> Optional[TreeNode]:
        arr = []
        while head:
            arr.append(head.val)
            head = head.next
        def dfs(left, right):
            if left > right: return
            m = (left + right)//2
            return TreeNode(arr[m], dfs(left, m-1), dfs(m+1, right))
        return dfs(0, len(arr)-1)