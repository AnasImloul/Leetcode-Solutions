# Runtime: 61 ms (Top 95.6%) | Memory: 16.68 MB (Top 75.1%)

class Solution:
    
    """
        Brute force kind of thing
        -> Inorder Traversal returns sorted array
        -> find a swap btwn numbers to make sorted
        Make single swap to make array sorted
        [1, 2, 3, 4, 10, 6, 9, 5, 10, 12]
         x, x, x, x, x, No
            prev number is mismatch -> 10 is cause
        now go frm right to left
        [1, 2, 3, 4, 10, 6, 9, 5, 11, 12]
                            No x   x   x
                        mismatch with next number -> 5 is the cause
        swap 10, 5
        
        Eg: 2
        [3, 2, 1]
         x  No -> 3 is the cause
        [3, 2, 1]
         x  No -> 1 is the cause
        swap values -> 1, 3
    """
    
    def inorder(self, root, li):
        if root is None:
            return li
        li = self.inorder(root.left, li)
        li.append(root)
        li = self.inorder(root.right, li)
        return li
    
    def recoverTree(self, root: TreeNode) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        li = self.inorder(root, [])
        n = len(li)
        i, j = 1, n-2
        a = li[0]
        for i in range(1, n):
            if li[i].val < li[i-1].val:
                a = li[i-1]
                break
        b = li[-1]
        for i in range(n-2, -1, -1):
            if li[i].val > li[i+1].val:
                b = li[i+1]
                break

        a.val,b.val = b.val, a.val
