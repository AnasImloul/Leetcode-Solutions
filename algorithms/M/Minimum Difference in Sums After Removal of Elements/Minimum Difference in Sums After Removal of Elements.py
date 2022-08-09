class Solution:
    def minimumDifference(self, nums: List[int]) -> int:
        h=heapq
        k=len(nums)//3
        min_heap, max_heap, min_sol, max_sol, min_sum, max_sum, sol=[] , [] , [] , [] , 0 , 0, []
        h.heapify(max_heap) , h.heapify(min_heap)
        for x in nums[:-k]:
            h.heappush(min_heap,-x)
            min_sum+=x
            if len(min_heap)>k: min_sum+=h.heappop(min_heap)
            min_sol.append(min_sum)
        for x in nums[::-1][:-k]:
            h.heappush(max_heap,x)
            max_sum+=x
            if len(max_heap)>k: max_sum-=h.heappop(max_heap)
            max_sol.append(max_sum)
        min_sol =min_sol[k-1:]
        max_sol=max_sol[k-1:][::-1]
        return min( min_value - max_value for min_value , max_value in zip(min_sol,max_sol) )
