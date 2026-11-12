# Runtime: 177 ms (Top 90.15%) | Memory: 102.70 MB (Top 6.06%)

class Solution:
    def treeQueries(self, root: Optional[TreeNode], queries: List[int]) -> List[int]:
        # Initialize arrays to store heights and node information
        heights = [0] * 50000  # Heights of leaf nodes
        d = [0] * 100001      # Depth of each node
        l = [0] * 100001      # Left index for each node
        r = [0] * 100001      # Right index for each node
        len_leaves = 0        # Counter for leaf nodes

        def search(p: TreeNode, h: int) -> None:
            nonlocal len_leaves
            d[p.val] = h  # Store current node's depth

            # If leaf node found
            if not p.left and not p.right:
                heights[len_leaves] = h    # Store leaf height
                l[p.val] = r[p.val] = len_leaves  # Both indices same for leaf
                len_leaves += 1
                return

            l[p.val] = len_leaves  # Store left index for current node

            # Recursively process left and right subtrees
            if p.left:
                search(p.left, h + 1)
            if p.right:
                search(p.right, h + 1)

            r[p.val] = len_leaves - 1  # Store right index for current node

        # Process the tree starting from root
        search(root, 0)

        n = len_leaves  # Total number of leaf nodes
        maxl = [0] * n  # Max heights from left
        maxr = [0] * n  # Max heights from right

        # Build prefix and suffix maximum arrays
        for i in range(1, n):
            maxl[i] = max(maxl[i-1], heights[i-1])  # Max height from left
            maxr[n-i-1] = max(maxr[n-i], heights[n-i])  # Max height from right

        ret = []  # Result list

        # Process each query
        for query in queries:
            # Find maximum height excluding current node's subtree
            maxxl = maxl[l[query]]  # Max height to the left
            maxxr = maxr[r[query]]  # Max height to the right
            # Result is max of (max left height, max right height, current depth-1)
            ret.append(max(max(maxxl, maxxr), d[query]-1))

        return ret
