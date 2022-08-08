class Solution:
    def numFactoredBinaryTrees(self, nums: List[int]) -> int:
        nums = set(nums)
        n = len(nums)
        
        @lru_cache(None)
        def helper(num):
            trees = 1
            for factor in nums:
                if not num % factor and num // factor in nums:
                    trees += helper(factor) * helper(num // factor)

            return trees
        
        return sum(helper(num) for num in nums) % (10 ** 9 + 7)