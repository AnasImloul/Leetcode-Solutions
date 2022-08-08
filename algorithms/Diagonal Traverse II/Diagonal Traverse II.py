class Solution:
    def findDiagonalOrder(self, nums: List[List[int]]) -> List[int]:
		# sort the index of element
        heap = list()
        n = len(nums)
        for i in range(n):
            m = len(nums[i])
            for j in range(m):
                heapq.heappush(heap,[i+j,j,i])
				
		# append the element one by one
        ans = []
        while heap:
            temp = heapq.heappop(heap)
            ans.append(nums[temp[2]][temp[1]])
        return ans
