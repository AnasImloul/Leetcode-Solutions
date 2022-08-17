class Solution:
    def halveArray(self, nums: List[int]) -> int:
        # Creating empty heap
        maxHeap = []
        heapify(maxHeap) # Creates minHeap 
        
        totalSum = 0
        for i in nums:
            # Adding items to the heap using heappush
            # for maxHeap, function by multiplying them with -1
            heappush(maxHeap, -1*i) 
            totalSum += i
        
        requiredSum = totalSum / 2
        minOps = 0
        
        while totalSum > requiredSum:
            x = -1*heappop(maxHeap) # Got negative value make it positive
            x /= 2
            totalSum -= x
            heappush(maxHeap, -1*x) 
            minOps += 1
        
        return minOps
