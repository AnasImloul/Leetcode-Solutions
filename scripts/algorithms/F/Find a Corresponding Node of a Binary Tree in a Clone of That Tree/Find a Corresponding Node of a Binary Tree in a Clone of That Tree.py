# Runtime: 1109 ms (Top 30.14%) | Memory: 24.2 MB (Top 19.53%)
class Solution:
    def getTargetCopy(self, original: TreeNode, cloned: TreeNode, target: TreeNode) -> TreeNode:
        def DFS(node1,node2):
            if node1==target:
                return node2
            if node1 and node1.left is None and node1.right is None:
                return

            res1 = DFS(node1.left,node2.left) if node1 else None
            if res1 is not None:
                return res1
            res2 = DFS(node1.right,node2.right) if node1 else None
            if res2 is not None:
                return res2
        res=DFS(original,cloned)
        return res