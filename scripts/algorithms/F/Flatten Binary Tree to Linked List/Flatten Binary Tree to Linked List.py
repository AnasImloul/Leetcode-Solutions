# Runtime: 59 ms (Top 52.37%) | Memory: 15.1 MB (Top 89.03%)
#Call the right of the tree node till the node root left and right is not None
#After reaching the bottom of the tree make the root.right = prev and
#root.left = None and then prev = None
#Initially prev will point to None but this is used to point the previously visited root node
#Prev pointer helps us to change the values from left to right
class Solution:
    def flatten(self, root: Optional[TreeNode]) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        prev = None #You can also define that variable inside the init function using self keyword
        def dfs(root):
            nonlocal prev

            if not root:
                return

            dfs(root.right)
            dfs(root.left)

            root.right = prev
            root.left = None
            prev = root

        dfs(root)
# If the above solution is hard to understand than one can do level order traversal
#Using Stack DS but this will increase the space complexity to O(N).