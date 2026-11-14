# Runtime: 229 ms (Top 12.50%) | Memory: 45.00 MB (Top 6.25%)

class Solution:
    def miceAndCheese(self, reward1: List[int], reward2: List[int], k: int) -> int:
        output = 0
        n = len(reward1)
        heap = []
        for i in range(n):
            heap.append((reward2[i] - reward1[i], i))

        heapq.heapify(heap)
        visited = set()
        while k:
            k -= 1
            _, idx = heapq.heappop(heap)
            visited.add(idx)
            output += reward1[idx]

        # If there is anything left that has not been taken, we take it from reward2.
        for idx, val in enumerate(reward2):
            if idx in visited:
                continue
            output += val

        return output
