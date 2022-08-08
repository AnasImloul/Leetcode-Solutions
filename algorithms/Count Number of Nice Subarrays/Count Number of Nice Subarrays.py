class Solution:
    def numberOfSubarrays(self, nums: List[int], k: int) -> int:
        d = defaultdict(int)
        d[0] = 1
        count = 0
        ans = 0
        for num in nums:
            if num % 2 == 1: count += 1
            ans += d[count - k]
            d[count] += 1
        return ans
