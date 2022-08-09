class Solution:
    def escapeGhosts(self, ghosts: List[List[int]], target: List[int]) -> bool:
        t = float('inf')
        tx, ty = target
        for i, j in ghosts:
            t = min(t, abs(tx - i) + abs(ty - j))
        return t > abs(tx) + abs(ty)
