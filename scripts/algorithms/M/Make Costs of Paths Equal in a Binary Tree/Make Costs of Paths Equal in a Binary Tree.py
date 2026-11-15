# Runtime: 253 ms (Top 22.06%) | Memory: 55.00 MB (Top 38.24%)

class Solution:
    def minIncrements(self, n: int, cost: List[int]) -> int:

        correction=0
        def dfs(node):
            nonlocal correction
            if node>=len(cost):
                return 0
            #the indexing is a bit annoying, but I like to think about it this way:
            #we have to treat it as being 1-indexed to get the child (so we use 2*(node+1) rather than 2*node)
            #we then convert it back to 0-indexed for the array (so 2*(node+1)-1)
            #I explain the indexing in more details in the comment section
            lcost=dfs(2*(node+1)-1)
            rcost=dfs(2*(node+1))
            correction+=abs(rcost-lcost)
            return max(lcost,rcost)+cost[node]

        dfs(0)
        return correction
