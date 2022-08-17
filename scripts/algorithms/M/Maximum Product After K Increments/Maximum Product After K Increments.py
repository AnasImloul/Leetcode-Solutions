import heapq

class Solution:
    def maximumProduct(self, nums, k: int) -> int:
        
        # creating a heap
        heap = []
        for i in nums:
            heapq.heappush (heap,i)
            
            
        # basic idea here is keep on incrementing smallest number, then only multiplication of that number will be greater
        # so basically till I have operations left I will increment my smallest number
        while k :
            current = heapq.heappop(heap)
            heapq.heappush(heap, current+1)
            k-=1
            
        result =1
        
        # Just Multiply all the numbers in heap and return the value
        while len(heap)>0:
            x= heapq.heappop(heap)
            result =(result*x )% (10**9+7)
            
        return result
