class Solution:
    def findJudge(self, n: int, trust: List[List[int]]) -> int:
        possible = set([i for i in range(1,n+1)])
        in_edges = [0] * (n+1)
        
        for first, second in trust:
            possible.discard(first)
            in_edges[second] += 1
            
        if len(possible) != 1:
            return -1
        
        i = possible.pop()
        if in_edges[i] == n-1:
            return i
        return -1
