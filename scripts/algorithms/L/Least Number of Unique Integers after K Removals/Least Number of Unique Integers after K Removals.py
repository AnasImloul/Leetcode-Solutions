from heapq import heapify, heappop
class Solution:
    def findLeastNumOfUniqueInts(self, arr: List[int], k: int) -> int:
        freqs = Counter(arr)
        counts = list(freqs.values())
        heapify(counts)
        while k > 0:
            if counts[0] <= k:
                k -= heappop(counts)
            else:
                break
        return len(counts)
