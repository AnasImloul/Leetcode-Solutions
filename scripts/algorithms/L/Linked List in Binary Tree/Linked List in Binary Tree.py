# Runtime: 139 ms (Top 73.10%) | Memory: 16.3 MB (Top 54.16%)

class Solution(object):
    def isSubPath(self, head, root):
        if not root:
            return False
        if self.issame(head, root):
            return True
        return self.isSubPath(head, root.left) or self.isSubPath(head, root.right)
    def issame(self, head, root):
        if not head:
            return True
        if not root:
            return False
        if head.val != root.val:
            return False
        return self.issame(head.next, root.left) or self.issame(head.next, root.right)