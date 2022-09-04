# Runtime: 95 ms (Top 8.35%) | Memory: 14.1 MB (Top 29.67%)
class Solution:
    def numRabbits(self, answers: List[int]) -> int:
        # store ans in ans_map
        ans_map = collections.Counter(answers)
        total = 0
        for ans, count in ans_map.items():
            total += (ans + 1) * ceil(count / (ans + 1))
        return total
