# Runtime: 492 ms (Top 22.46%) | Memory: 20 MB (Top 17.02%)
class Solution:
    def isPossible(self, target: List[int]) -> bool:
        if len(target) == 1:
            return target == [1]
        res = sum(target)
        heap = [-elem for elem in target]
        heapify(heap)
        while heap[0]<-1:
            maximum = -heappop(heap)
            res -= maximum

            if res == 1:
                return True
            x = maximum % res
            if x == 0 or (x != 1 and x == maximum):
                return False

            res += x
            heappush(heap,-x)
        return True