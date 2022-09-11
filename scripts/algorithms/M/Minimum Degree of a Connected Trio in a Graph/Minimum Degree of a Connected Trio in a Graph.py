# Runtime: 1826 ms (Top 63.02%) | Memory: 50.7 MB (Top 5.73%)
class Solution:
    def minTrioDegree(self, n: int, edges: List[List[int]]) -> int:
        result = n ** 2 # placeholder value
        adj = [set() for _ in range(n + 1)]
        visited = set()
        for edge in edges:
            adj[edge[0]].add(edge[1])
            adj[edge[1]].add(edge[0])
        for first in range(1, n + 1): # iterate through every node
            for second in adj[first]: # iterate through every neighbor of the first node
                e1 = tuple(sorted((first, second)))
                if e1 in visited:
                    continue
                visited.add(e1) # mark e1 (first -> second) as visited because we don't want to visit (second -> first) again
                for third in adj[second]:
                    if third == first: # skip if the third node is the first node (we need the first node to be its neighbor rather than itself!)
                        continue
                    e2 = tuple(sorted((first, third)))
                    if first in adj[third]: # we don't check if e2 is in visited because the third node is not the current node being explored
                        visited.add(e2) # we need to mark e2 as visited because one end of e2 is the first node and if we have checked (third -> first), we don't need to check (first -> third) again
                        degree = len(adj[first]) - 2 + len(adj[second]) - 2 + len(adj[third]) - 2
                        result = min(result, degree)
        return -1 if result == n ** 2 else result