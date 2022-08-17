class Solution:
    def minimumRounds(self, tasks: List[int]) -> int:
        cnt = Counter(tasks).values()
        return -1 if 1 in cnt else sum((t + 2) // 3 for t in cnt)
