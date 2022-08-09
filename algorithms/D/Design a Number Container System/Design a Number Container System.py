class NumberContainers:
    def __init__(self):
        self.numbersByIndex = {}
        self.numberIndexes = defaultdict(set)
        self.numberIndexesHeap = defaultdict(list)

    def change(self, index: int, number: int) -> None:
        if index in self.numbersByIndex:
            if number != self.numbersByIndex[index]:
                self.numberIndexes[self.numbersByIndex[index]].remove(index)
                self.numbersByIndex[index] = number
                self.numberIndexes[number].add(index)
                heappush(self.numberIndexesHeap[number], index)
        else:
            self.numbersByIndex[index] = number
            self.numberIndexes[number].add(index)
            heappush(self.numberIndexesHeap[number], index)

    def find(self, number: int) -> int:
        while self.numberIndexesHeap[number] and self.numberIndexesHeap[number][0] not in self.numberIndexes[number]:
                heappop(self.numberIndexesHeap[number])  # make sure the smallest index in heap is still an index for number
        return self.numberIndexesHeap[number][0] if self.numberIndexesHeap[number] else -1

