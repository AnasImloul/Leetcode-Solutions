# Runtime: 75 ms (Top 66.15%) | Memory: 32.60 MB (Top 67.69%)

class Solution:
    def minimumCost(self, nums: List[int]) -> int:

        nums.sort()
        pal = lambda x: str(x) == str(x)[::-1]
        left = rght = nums[len(nums)//2]

        while not pal(left): left-= 1
        while not pal(rght): rght+= 1

        return min(sum(map(lambda x: abs(x - left), nums)),
                   sum(map(lambda x: abs(x - rght), nums)))
