class Solution:
    def deleteAndEarn(self, nums: List[int]) -> int:
        count = Counter(nums)
        m = max(nums)
        memo = {}
        def choose(num):
            if num > m:
                return 0
            if num not in count:
                count[num] = 0
            if num in memo:
                return memo[num]
            memo[num] = max(choose(num + 1), num * count[num] + choose(num + 2))
            return memo[num]
        
        return choose(1)

# time and space complexity
# n = max(nums)
# time: O(n)
# space: O(n)
            
            
