class SmallestInfiniteSet:

    def __init__(self):
        self.index = 1
        self.heap = []

    def popSmallest(self) -> int:
        if self.heap:
            return heapq.heappop(self.heap)
        self.index += 1
        return self.index-1

    def addBack(self, num: int) -> None:
        if self.index > num and num not in self.heap:
            heapq.heappush(self.heap,num)
