// Runtime: 2057 ms (Top 36.95%) | Memory: 122.60 MB (Top 98.09%)

class Solution:
    def countSubTrees(self, n: int, edges: List[List[int]], labels: str) -> List[int]:
        # Construct the tree using the edges.
        # Since the tree is undricted, we need to add both directions in the tree.
        tree = defaultdict(list)
        for s,e in edges:
            tree[s].append(e)
            tree[e].append(s)
        
        # The result of length n will be returned at the end.
        # It is being modified in the dfs.
        res = [0] * n
        
        # node is the current node we are examing.
        # par is the node's direct parent node.
        def dfs(node, par):
            nonlocal res
            # Using count to store the count of each letters in the sub-tree rooted at the current node.
            # The size of this hashmap (count) will be at most 26, 
            # Since there are at most 26 lowercase English letters 
            count = Counter()
            for nei in tree[node]:
                # Make sure we are not going backward to its parent node.
                if nei != par:
                    # Update count with the letters' frequency in the children nodes
                    # This is the same as going through a to z and increase the frequency of each letter.
                    count += dfs(nei, node)
            
            # Adding 1 to count with the current label
            count[labels[node]] += 1
            # Update the result.
            res[node] = count[labels[node]]
            
            return count
        
        # Starting from node 0, and assign fake parent -1 for it.
        dfs(0,-1)
        return res
