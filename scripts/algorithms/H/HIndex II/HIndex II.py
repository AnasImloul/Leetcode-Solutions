# Runtime: 95 ms (Top 96.2%) | Memory: 17.82 MB (Top 71.8%)

class Solution(object):
    def hIndex(self, citations):
        """
        :type citations: List[int]
        :rtype: int
        """
        # for i in range(len(citations)):
        #     if len(citations) - i <= citations[i]:
        #         return len(citations) - i
        # return 0
        left, right, mid = 0, len(citations) - 1, 0
        while left < right:
            mid = (left + right) // 2
            if len(citations) - mid <= citations[mid]: right = mid
            else: left = mid + 1
        if citations[left] == 0: return 0 
        return len(citations) - left 