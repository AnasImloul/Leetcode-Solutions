class MedianFinder:

    def __init__(self):
        self.min_hp = []
        self.max_hp = []
        
    def addNum(self, num: int) -> None:
        if len(self.min_hp) == len(self.max_hp):
            if len(self.max_hp) and num<-self.max_hp[0]:
                cur = -heapq.heappop(self.max_hp)
                heapq.heappush(self.max_hp, -num)
                heapq.heappush(self.min_hp, cur)
            else:
                heapq.heappush(self.min_hp, num)
        else:
            if num>self.min_hp[0]:
                cur = heapq.heappop(self.min_hp)
                heapq.heappush(self.min_hp, num)
                heapq.heappush(self.max_hp, -cur)
            else:
                heapq.heappush(self.max_hp, -num)
        
    def findMedian(self) -> float:
        if len(self.min_hp) == len(self.max_hp):
            return (self.min_hp[0] + -self.max_hp[0]) /2
        else:
            return self.min_hp[0]
