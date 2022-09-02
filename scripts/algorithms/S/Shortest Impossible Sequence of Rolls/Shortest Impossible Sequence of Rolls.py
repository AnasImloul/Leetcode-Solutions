# Runtime: 966 ms (Top 94.20%) | Memory: 28.2 MB (Top 71.33%)
class Solution:
    def shortestSequence(self, rolls: List[int], k: int) -> int:
        ans = 1
        data = set()

        for roll in rolls:
            data.add(roll)

            if len(data) == k:
                ans += 1
                data.clear()

        return ans