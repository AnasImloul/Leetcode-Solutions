class Solution:
    def countTriplets(self, nums: List[int]) -> int:
        ans = 0
        mem = [0] * (1 << 16)
        size = len(nums)

        for i in range(size):
            for j in range(i, size):
                mem[nums[i]&nums[j]] += 2 if i != j else 1
        
        for ij in range(1 << 16):
            if mem[ij] > 0:
                for k in nums:
                    if k & ij == 0:
                        ans += mem[ij]
        return ans
