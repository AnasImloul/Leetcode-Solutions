# defaultdict is the same as Python's usual dictionary, but if an
# element doesn't exist, you can give it a default value to initialize with. 
from collections import defaultdict
# nlargest(n, l) - returns the n largest values of collection l.
from heapq import nlargest
# "product" is a function that takes two collections and 
# returns every pair between them.
# product("ab", "cd") = [(a, c), (a, d), (b, c), (b, d)].
from itertools import product

Let V be the number of nodes and E = len(edges).
# Time complexity: O(V + E) - we iterate through every vertex 
#                  and every edge a constant number of times.
# Space complexity: O(V) - we save a constant 
#                   number of neighbors (3) for every node.
class Solution:
    def maximumScore(self, scores: List[int], edges: List[List[int]]) -> int:
        # Turn the edge list into an adjacency graph.
        m = defaultdict(list)
        for u, v in edges:
            m[u].append((scores[v], v)) 
            m[v].append((scores[u], u))
        
        # Cut down all neighbors of each node to the three
        # that have the highest value.
        for u in m:
            m[u] = nlargest(3, m[u])

        ret = -1
        # Consider each edge to potentially be (B, C) for a quadruplet.
        for b, c in edges:
            # For every possible A and D in the neighbors of B and C...
            for (aWeight, a), (dWeight, d) in product(m[b], m[c]):
                # ... If we have no redundant nodes, it's a quadruplet.
                # Since it's the highest value quadruplet we could
                # possibly make with B and C, this solution is always accurate.
                if a not in [b, c] and d not in [b, c] and a != d:
                    ret = max(ret, scores[b] + scores[c] + aWeight + dWeight)
                    
        return ret
