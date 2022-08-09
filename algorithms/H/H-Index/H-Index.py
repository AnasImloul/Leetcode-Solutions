class Solution:
    def hIndex(self, citations: List[int]) -> int:
        num = sorted(citations)
        h = 0
        j = len(num)-1
        for i in range(len(num)):
            if i+1 <=num[i] and j-i+1>=num[i]:
                h =max(num[i],h)
            elif i+1 <= num[i] and j-i+1<num[i]:
                h = max(h,j-i+1)
            elif i+1 > num[i] and j-i+1 >=num[i]:
                h = max(h, num[i])
            
        return h
