# Runtime: 1341 ms (Top 80.70%) | Memory: 40.9 MB (Top 9.94%)

from heapq import *

class MinHeapItem:
    def __init__(self, name, score):
        self.name = name
        self.score = score
    def __lt__(self, other):
        return self.score < other.score or \
               (self.score == other.score and self.name > other.name)

class MaxHeapItem:
    def __init__(self, name, score):
        self.name = name
        self.score = score
    def __lt__(self, other):
        return self.score > other.score or \
               (self.score == other.score and self.name < other.name)

class SORTracker:
    def __init__(self):
        self.min_heap = []
        self.max_heap = []
        self.i = 1

    def add(self, name: str, score: int) -> None:
        current = MinHeapItem(name, score)
        if len(self.min_heap) < self.i:
            heappush(self.min_heap, current)
        elif current > self.min_heap[0]:
            temp = heapreplace(self.min_heap, current)
            heappush(self.max_heap, MaxHeapItem(temp.name, temp.score))
        else:
            heappush(self.max_heap, MaxHeapItem(name, score))

    def get(self) -> str:
        ans = self.min_heap[0].name
        self.i += 1
        if self.max_heap:
            temp = heappop(self.max_heap)
            heappush(self.min_heap, MinHeapItem(temp.name, temp.score))
        return ans