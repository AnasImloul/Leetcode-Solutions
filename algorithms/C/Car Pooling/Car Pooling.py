class Solution:
    def carPooling(self, trips: List[List[int]], capacity: int) -> bool:
        endheap = []
        startheap = []
        
        for i in range(len(trips)):
            endheap.append((trips[i][2],trips[i][0],trips[i][1]))
            startheap.append((trips[i][1],trips[i][0],trips[i][2]))
        heapify(endheap)
        heapify(startheap)
        cur = 0
        while startheap:
            start,num,end = heappop(startheap)
            while start >= endheap[0][0]:
                newend,newnum,newstart = heappop(endheap)
                cur -= newnum
            cur += num
            print(cur)
            if cur >capacity:
                return False
        return True
                
                
            
        
