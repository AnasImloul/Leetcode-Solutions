class Solution:
    def reductionOperations(self, nums: List[int]) -> int:
        return sum(accumulate(c for _,c in sorted(Counter(nums).items(), reverse=True)[:-1]))
