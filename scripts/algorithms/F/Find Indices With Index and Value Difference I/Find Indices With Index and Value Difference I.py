# Runtime: 2 ms (Top 48.18%) | Memory: 19.30 MB (Top 20.91%)

class Solution:
    def findIndices(self, nums: List[int], indexDifference: int,
                    valueDifference: int) -> List[int]:

        if indexDifference == valueDifference == 0: return [0,0]

        pairs = filter(lambda x: x[1]-x[0] >= indexDifference,
                        combinations(range(len(nums)),2))

        for i,j in pairs:
            if abs(nums[i] - nums[j]) >= valueDifference: return [i,j]

        return [-1,-1]
