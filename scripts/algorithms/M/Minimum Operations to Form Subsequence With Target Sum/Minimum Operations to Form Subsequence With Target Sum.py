# Runtime: 4 ms (Top 45.83%) | Memory: 19.50 MB (Top 25.00%)

class Solution:
    def minOperations(self, nums: List[int], target: int) -> int:
        if sum(nums) < target:
            return -1
        cnt = [0] * 32
        for num in nums:
            cnt[int(math.log2(num))] += 1

        ans = 0

        for i in range(31):
            if (target // (2**i)) & 1:
                if cnt[i] > 0:
                    cnt[i] -= 1
                else:
                    j = i + 1
                    while cnt[j] == 0:
                        j += 1
                    cnt[i] += 2**(j - i)
                    cnt[j] -= 1
                    cnt[i] -= 1
                    ans += (j - i)
            cnt[i + 1] += cnt[i] // 2
        return ans
