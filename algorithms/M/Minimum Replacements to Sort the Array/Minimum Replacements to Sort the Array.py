class Solution:
    def minimumReplacement(self, nums) -> int:
        ans = 0
        n = len(nums)
        curr = nums[-1]
        for i in range(n - 2, -1, -1):
            if nums[i] > curr:
                q = nums[i] // curr
                if nums[i] == curr * q:
                    nums[i] = curr
                    ans += q - 1
                else:
                    nums[i] = nums[i] // (q + 1)
                    ans += q
            curr = nums[i]
        return ans
