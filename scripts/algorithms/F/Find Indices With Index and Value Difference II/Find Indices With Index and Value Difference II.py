# Runtime: 53 ms (Top 19.70%) | Memory: 33.40 MB (Top 45.45%)

class Solution:
    def findIndices(self, nums: List[int], indexDifference: int, valueDifference: int) -> List[int]:
        mn = mx = -1 
        for i, x in enumerate(nums): 
            if i >= indexDifference: 
                if mn == -1 or nums[i-indexDifference] < nums[mn]: mn = i-indexDifference
                if mx == -1 or nums[i-indexDifference] > nums[mx]: mx = i-indexDifference
                if x - nums[mn] >= valueDifference: return [mn, i]
                if nums[mx] - x >= valueDifference: return [mx, i]
        return [-1, -1]
