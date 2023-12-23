// Runtime: 62 ms (Top 9.13%) | Memory: 17.50 MB (Top 9.13%)

class Solution:
    def escapeGhosts(self, ghosts: List[List[int]], target: List[int]) -> bool:
        
        dist = lambda x : abs(x[0] - target[0]) + abs(x[1] - target[1])

        return dist((0,0)) < min(dist(g) for g in ghosts)
