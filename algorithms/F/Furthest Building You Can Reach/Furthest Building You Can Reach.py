class Solution:
    def furthestBuilding(self, H: List[int], B: int, L: int) -> int:
        heap = []
        for i in range(len(H) - 1):
            diff = H[i+1] - H[i]
            if diff > 0:
                if L > 0:
                    heappush(heap, diff)
                    L -= 1
                elif heap and diff > heap[0]:
                    heappush(heap, diff)
                    B -= heappop(heap)
                else: B -= diff
                if B < 0: return i
        return len(H) - 1
