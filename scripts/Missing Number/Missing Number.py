class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        # T.C = O(n) S.C = O(1)
        actualsum = 0
        currentsum = 0
        i = 1
        for num in nums:
            currentsum += num
            actualsum += i
            i += 1
        
        return actualsum - currentsum