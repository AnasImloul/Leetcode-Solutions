class Solution(object):
    def maxChunksToSorted(self, arr):
        n= len(arr)

        count=0
        currentmax= -2**63
        for i in range(0,n):
            currentmax=max(currentmax, arr[i])
            if (currentmax==i):
                count+=1
        return count
        
        
    
