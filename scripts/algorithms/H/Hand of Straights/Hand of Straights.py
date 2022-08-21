# Runtime: 304 ms (Top 61.38%) | Memory: 15.7 MB (Top 75.38%)

#####################################################################################################################
# Problem: Hand of Straights
# Solution : Hash Table, Min Heap
# Time Complexity : O(n logn)
# Space Complexity : O(n)
#####################################################################################################################

class Solution:
    def isNStraightHand(self, hand: List[int], groupSize: int) -> bool:
        if len(hand) % groupSize:
            return False

        freq = collections.defaultdict(int)

        for num in hand:
            freq[num] += 1

        min_heap = list(freq.keys())
        heapq.heapify(min_heap)

        while min_heap:
            smallest = min_heap[0]
            for num in range(smallest, smallest + groupSize):
                if num not in freq:
                    return False
                freq[num] -= 1

                if freq[num] == 0:
                    if num != min_heap[0]:
                        return False
                    heapq.heappop(min_heap)
        return True