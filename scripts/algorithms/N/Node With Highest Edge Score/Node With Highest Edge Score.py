# Runtime: 170 ms (Top 25.83%) | Memory: 35.20 MB (Top 43.71%)

class Solution:
    def edgeScore(self, edges: list[int]) -> int:
        score = defaultdict(int)

        for u, v in enumerate(edges):
            score[v] += u

        return max(score, key=lambda x: (score[x], -x))
