from heapq import heappop, heapify

class Solution:
    def findLeastNumOfUniqueInts(self, arr: List[int], k: int) -> int:
        counter = collections.Counter(arr)
        min_heap = [(count, num) for num, count in counter.items()]

        heapify(min_heap)

        while k > 0:
            count, num = min_heap[0]

            if count > k:
                break

            heappop(min_heap)
            k -= count

        return len(min_heap)