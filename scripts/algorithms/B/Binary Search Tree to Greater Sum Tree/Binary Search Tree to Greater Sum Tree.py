# Runtime: 69 ms (Top 6.93%) | Memory: 14.1 MB (Top 33.83%)
class Solution:
    def bstToGst(self, root: TreeNode) -> TreeNode:
        '''
        Left - root - right : gives sorted ordering of nodes - O(n)
        Then find prefix sum of the sorted array from the right side - O(n)
        Then do binary search on inorder array and get the prefix sum - O(nlogn) since we do binary search for each node
        '''

        #find the inorder traversal
        def inorder(node,arr):
            if not node: return

            inorder(node.left,arr)
            arr.append(node.val)
            inorder(node.right,arr)

        arr = []
        inorder(root,arr)
        n = len(arr)

        #find the prefix sum
        prefix = [num for num in arr]
        i = n-2
        while i>=0:
            prefix[i] += prefix[i+1]
            i-=1

        #do binary search and fill in the prefix sum for each node
        def fill(node):
            if not node: return

            i = bisect_left(arr,node.val)
            node.val = prefix[i]

            fill(node.right)
            fill(node.left)

        fill(root)
        return root